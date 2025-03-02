#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 64
// amount of memory allocated for input_data
#define INPUT_DATA_SIZE 5
// amount of memory allocated for safe_var
#define SAFE_VAR_SIZE 5

int num_allocs;
char *safe_var;
char *input_data;

void check_win()
{
    if (strcmp(safe_var, "bico") != 0)
    {
        printf("\nYOU WIN\n");

        // Print flag
        char buf[FLAGSIZE_MAX];
        FILE *fd = fopen("flag.txt", "r");
        if (fd == NULL)
        {
            perror("Error opening flag.txt");
            exit(1);
        }
        fgets(buf, FLAGSIZE_MAX, fd);
        printf("%s\n", buf);
        fclose(fd); // Make sure to close the file
        fflush(stdout);

        exit(0);
    }
    else
    {
        printf("Looks like everything is still secure!\n");
        printf("\nNo flag for you :(\n");
        fflush(stdout);        
    }
}

void print_menu()
{
    printf("\n1. Print Heap:\t\t(print the current state of the heap)"
           "\n2. Write to buffer:\t(write to your own personal block of data "
           "on the heap)"
           "\n3. Print safe_var:\t(I'll even let you look at my variable on "
           "the heap, "
           "I'm confident it can't be modified)"
           "\n4. Print Flag:\t\t(Try to print the flag, good luck)"
           "\n5. Exit\n\nEnter your choice: ");
    fflush(stdout);
}

void init()
{
    printf("\nWelcome to heap0!\n");
    printf(
        "I put my data on the heap so it should be safe from any tampering.\n");
    printf("Since my data isn't on the stack I'll even let you write whatever "
           "info you want to the heap, I already took care of using malloc for "
           "you.\n\n");
    fflush(stdout);

    input_data = malloc(INPUT_DATA_SIZE);
    if (input_data == NULL)
    {
        perror("Error allocating memory for input_data");
        exit(1);
    }

    strncpy(input_data, "pico", INPUT_DATA_SIZE - 1);
    input_data[INPUT_DATA_SIZE - 1] = '\0'; // Ensure null-termination

    safe_var = malloc(SAFE_VAR_SIZE);
    if (safe_var == NULL)
    {
        perror("Error allocating memory for safe_var");
        exit(1);
    }

    strncpy(safe_var, "bico", SAFE_VAR_SIZE - 1);
    safe_var[SAFE_VAR_SIZE - 1] = '\0'; // Ensure null-termination
}

void write_buffer()
{
    printf("Data for buffer: ");
    fflush(stdout);

    // Clear the input buffer before reading new input
    while (getchar() != '\n'); // Discard any leftover newline character
    
    // Use fgets to safely read input
    if (fgets(input_data, INPUT_DATA_SIZE, stdin) == NULL)
    {
        printf("Error reading input\n");
        exit(1);
    }

    // Remove newline if present
    input_data[strcspn(input_data, "\n")] = '\0';
    printf("Data written: %s\n", input_data);
}

void print_heap()
{
    printf("Heap State:\n");
    printf("+-------------+----------------+\n");
    printf("[*] Address   ->   Heap Data   \n");
    printf("+-------------+----------------+\n");
    printf("[*]   %p  ->   %s\n", (void *)input_data, input_data);
    printf("+-------------+----------------+\n");
    printf("[*]   %p  ->   %s\n", (void *)safe_var, safe_var);
    printf("+-------------+----------------+\n");
    fflush(stdout);
}

int main(void)
{
    // Setup
    init();
    print_heap();

    int choice;

    while (1)
    {
        while (getchar() != '\n'); // Discard any leftover newline character
        print_menu();
        int rval = scanf("%d", &choice);
        if (rval == EOF)
        {
            printf("Error reading input\n");
            exit(1);
        }
        if (rval != 1)
        {
            printf("Invalid input. Exiting...\n");
            exit(1);
        }

        switch (choice)
        {
        case 1:
            // Print heap
            print_heap();
            break;
        case 2:
            write_buffer();
            break;
        case 3:
            // Print safe_var
            printf("\n\nTake a look at my variable: safe_var = %s\n\n", safe_var);
            fflush(stdout);
            break;
        case 4:
            // Check for win condition
            check_win();
            break;
        case 5:
            // Exit
            return 0;
        default:
            printf("Invalid choice\n");
            fflush(stdout);
        }
    }
}
