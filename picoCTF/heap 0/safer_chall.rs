use std::fs::File;
use std::io::{self, Write, Read};
use std::process::exit;

struct Game {
    input_data: String,
    safe_var: String,
}

impl Game {
    fn new () -> Game {
        Game {
            input_data: String::from("pico"),
            safe_var: String::from("bico"),
        }
    }

    fn check_win(&self) {
        if self.safe_var != "bico" {
            println!("\nYOU WIN\n");
            let mut buf = String::new();
            let mut file = File::open("flag.txt").expect("Error opening flag.txt");
            file.read_to_string(&mut buf).expect("Error reading flag.txt");
            println!("{}", buf);
            exit(0);
        } else {
            println!("Looks like everything is still secure!");
            println!("\nNo flag for your :(");
        }
    }

    fn print_menu(&self) {
        println!(
            "\n1. Print Heap:\t\t(print the current state of the heap)
            \r2. Write to buffer:\t(write to your own personal block of data on the heap)
            \r3. Print safe_var:\t(I'll even let you look at my variable on the heap, I'm confident it can't be modified)
            \r4. Print Flag:\t\t(Try to print the flag, good luck)
            \r5. Exit
            \rEnter your choice: "
        );
    } 

    fn print_heap(&self) {
        println!("Heap State:");
        println!("+-------------+----------------+");
        println!("[*] Address   ->   Heap Data");
        println!("+-------------+----------------+");
        println!("[*]   {:?}  ->   {}", &self.input_data as *const _, self.input_data);
        println!("+-------------+----------------+");        
        println!("[*]   {:?}  ->   {}", &self.safe_var as *const _, self.safe_var);
        println!("+-------------+----------------+");
    }

    fn write_buffer(&mut self) {
        print!("Data for buffer:");
        io::stdout().flush().unwrap();

        let mut buffer = String::new();
        io::stdin().read_line(&mut buffer).unwrap();
        self.input_data = buffer.trim().to_string();
    }

    fn show_safe_var(&self) {
        println!("\n\nTake a look at my variable: safe_var = {}", self.safe_var);
    }
}

fn main() {
    let mut game = Game::new();

    // Print the initial heap state
    game.print_heap();

    loop {
        game.print_menu();
        let mut choice = String::new();
        io::stdin().read_line(&mut choice).unwrap();
        let choice: usize = match choice.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input '{}'. Exiting ...", choice);
                exit(1);
            }
        };

        match choice {
            1 => game.print_heap(),
            2 => game.write_buffer(),
            3 => game.show_safe_var(),
            4 => game.check_win(),
            5 => return, // Exit
            _ => println!("Invalid choice"),
        }
    }
}
