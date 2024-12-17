mod constants;
mod api;
mod utils;

fn main() {
    println!("Welcome to the CTF Challenge Template CLI!");

    // Step 1: Gather Challenge Details
    let (challenge_name, platform, category, difficulty, objective) = utils::gather_challenge_details();

    // Step 2: Replace Placeholders in the Template
    utils::replace_placeholders_in_template(&challenge_name, &platform, &category, &difficulty, &objective);
}
