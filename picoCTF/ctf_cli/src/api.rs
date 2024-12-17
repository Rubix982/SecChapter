use std::io;
use std::io::Write;
use reqwest::blocking::Client;
use serde::{Deserialize, Serialize};
use crate::{constants};

// Struct for OpenAI API
#[derive(Serialize)]
struct OpenAIRequest {
    model: String,
    messages: Vec<ChatMessage>,
}

#[derive(Serialize)]
struct ChatMessage {
    role: String,
    content: String,
}

#[derive(Deserialize)]
struct OpenAIResponse {
    choices: Vec<Choice>,
}

#[derive(Deserialize)]
struct Choice {
    message: ChatMessageContent,
}

#[derive(Deserialize)]
struct ChatMessageContent {
    content: String,
}

// Function to prompt for input
pub(crate) fn prompt(message: &str) -> String {
    print!("{}", message);
    io::stdout().flush().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

// Function to generate an objective using OpenAI API
pub(crate) fn generate_objective(
    challenge_name: &str,
    platform: &str,
    category: &str,
    difficulty: &str,
) -> Result<String, Box<dyn std::error::Error>> {
    let prompt_message = format!(
        "Generate a brief objective for a CTF challenge. Details: \
        Name: {}, Platform: {}, Category: {}, Difficulty: {}.",
        challenge_name, platform, category, difficulty
    );

    let client = Client::new();
    let request_body = OpenAIRequest {
        model: "gpt-4".to_string(),
        messages: vec![
            ChatMessage {
                role: "system".to_string(),
                content: "You are a helpful assistant that generates concise objectives for CTF challenges.".to_string(),
            },
            ChatMessage {
                role: "user".to_string(),
                content: prompt_message,
            }],
    };

    let response = client
        .post(constants::OPENAI_CHAT_ENDPOINT)
        .header("Authorization", format!("Bearer {}", constants::OPENAI_API_KEY))
        .json(&request_body)
        .send()?;

    let response_json: OpenAIResponse = response.json()?;
    if let Some(choice) = response_json.choices.get(0) {
        Ok(choice.message.content.trim().to_string())
    } else {
        Err("Failed to generate an objective.".into())
    }
}
