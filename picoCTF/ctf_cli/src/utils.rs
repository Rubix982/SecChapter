use std::{env, fs, io};
use std::path::Path;
use crate::{api, constants};

pub(crate) fn gather_challenge_details() -> (String, String, String, String, String) {
    let challenge_name = api::prompt("Enter Challenge Name: ");
    let platform = api::prompt("Enter Platform (picoCTF, HackTheBox, etc.): ");
    let category = api::prompt("Enter Category (Crypto, Web, Binary, etc.): ");
    let difficulty = api::prompt("Enter Difficulty (Easy | Medium | Hard): ");

    println!("Do you want to generate the Objective using ChatGPT? (y/n): ");
    let mut choice = String::new();
    io::stdin().read_line(&mut choice).unwrap();

    let objective = if choice.trim().eq_ignore_ascii_case("y") {
        println!("Generating Objective using ChatGPT...");
        api::generate_objective(&challenge_name, &platform, &category, &difficulty).unwrap_or_else(|e| {
            eprintln!("Error generating objective: {}", e);
            api::prompt("Enter Objective manually: ")
        })
    } else {
        api::prompt("Enter Objective: ")
    };
    (challenge_name, platform, category, difficulty, objective)
}

pub(crate) fn replace_placeholders_in_template(
    challenge_name: &String,
    platform: &String,
    category: &String,
    difficulty: &String,
    objective: &String,
) {
    // Step 1: Create the directory for the challenge
    let current_dir = env::current_dir().expect("Failed to get current directory");
    let parent_dir = current_dir
        .parent()
        .expect("Failed to get parent directory of current directory");

    let folder_name = challenge_name.replace(" ", "_");
    let challenge_path = parent_dir.join(&folder_name);

    println!("Creating folder: {}", challenge_path.display());
    fs::create_dir_all(&challenge_path).expect("Failed to create challenge folder");

    // Step 2: Copy the template file and place it under the newly created directory
    let template_path = constants::TEMPLATE_FILE;
    let template_path_expanded = shellexpand::tilde(&template_path).to_string();
    let template_path = Path::new(&template_path_expanded);
    let destination_path = challenge_path.join("README.md");

    println!("Copying template from {} to {}", template_path.display(), destination_path.display());

    fs::copy(&template_path, &destination_path).expect("Failed to copy template file to destination");

    // Step 3: Read the contents of the template
    let template_content = fs::read_to_string(template_path).expect("Failed to read template file");

    // Step 4: Replace the placeholders in the template content
    let filled_template = template_content
        .replace("[Challenge Name]", &challenge_name)
        .replace("[picoCTF, HackTheBox, TryHackMe, etc.]", &platform)
        .replace("[Crypto, Web, Binary Exploitation, Forensics, etc.]", &category)
        .replace("[Easy | Medium | Hard]", &difficulty)
        .replace("[Brief description of the challenge]", &objective);

    // Step 5: Write the modified content to the destination file
    fs::write(&destination_path, filled_template).expect("Failed to write template to file");

    // Step 6: Log success
    println!("Template saved to {}", &destination_path.display());
    println!("Challenge setup complete!");
}

