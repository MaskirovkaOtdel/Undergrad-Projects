#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBERS 100  // Maximum number of numbers

// Function declarations
void apolyth_timh();
void generate_random_numbers();
double calculate_standard_deviation(float numbers[], int n);
void calculate_and_display_statistics();
void save_to_csv(float numbers[], int n);
void compare_sets_of_numbers();
void handle_error(const char *message);

// Function to clear the input buffer
void clear_input_buffer() {
    while (getchar() != '\n');  // Clear the buffer
}

// Function to validate if the input is a valid number
int is_valid_number(char *input) {
    char *endptr;
    strtod(input, &endptr);  // Use strtod to check if it's a valid number
    return (*endptr == '\0' || *endptr == '\n');  // Check if it's valid
}

// Function to calculate the standard deviation
double calculate_standard_deviation(float numbers[], int n) {
    float sum = 0.0, mean, standard_deviation = 0.0;
    int i;

    // Calculate the mean
    for(i = 0; i < n; i++) {
        sum += numbers[i];
    }
    mean = sum / n;

    // Calculate the standard deviation
    for(i = 0; i < n; i++) {
        standard_deviation += pow(numbers[i] - mean, 2);
    }
    return sqrt(standard_deviation / n);
}

// Function to calculate absolute values and other statistics
void calculate_and_display_statistics() {
    int n, i;
    char input[100];
    printf("Posous arithmous thelete na eisagete? ");
    
    // Input validation for the number of elements
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (is_valid_number(input)) {
            n = atoi(input);
            break;
        } else {
            printf("Parakalw eisagete valid number.\n");
        }
    }

    // Dynamically allocate memory for the numbers
    float *numbers = (float *)malloc(n * sizeof(float));
    if (numbers == NULL) {
        handle_error("Memory allocation failed.");
        return;
    }

    // Input numbers
    for (i = 0; i < n; i++) {
        while(1) {
            printf("Eisagete ton %d arithmo: ", i + 1);
            fgets(input, sizeof(input), stdin);
            if (is_valid_number(input)) {
                numbers[i] = atof(input);
                break;
            } else {
                printf("Parakalw eisagete valid number.\n");
            }
        }
    }

    // Calculate the absolute value sum
    float sum = 0;
    for (i = 0; i < n; i++) {
        sum += fabs(numbers[i]);
    }

    // Calculate the average
    float average = sum / n;

    // Calculate the standard deviation
    double std_dev = calculate_standard_deviation(numbers, n);

    // Display results
    printf("\nApotelesmata:\n");
    printf("Mesos oros tis apolyths timhs: %.2f\n", average);
    printf("Tupiki apoklish: %.2f\n", std_dev);

    // Add saving results to CSV
    save_to_csv(numbers, n);

    // Free allocated memory
    free(numbers);
}

// Function to save results to a CSV file
void save_to_csv(float numbers[], int n) {
    FILE *file = fopen("results.csv", "w");
    if (file == NULL) {
        handle_error("Apotuxia anoigmatos arxeiou.");
        return;
    }
    fprintf(file, "Number, Absolute Value\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%.2f, %.2f\n", numbers[i], fabs(numbers[i]));
    }
    fclose(file);
    printf("Ta apotelesmata apothikeftikan sto arxeio 'results.csv'.\n");
}

// Function to compare two sets of numbers
void compare_sets_of_numbers() {
    int n1, n2;
    char input[100];

    // Input first set size
    printf("Posous arithmous thelete na eisagete sto prwto set? ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (is_valid_number(input)) {
            n1 = atoi(input);
            if (n1 > 0) break;
        }
        printf("Parakalw eisagete valid number (positivos arithmos) gia to prwto set: ");
    }

    // Dynamically allocate memory for the first set
    float *numbers1 = (float *)malloc(n1 * sizeof(float));
    if (numbers1 == NULL) {
        handle_error("Memory allocation failed.");
        return;
    }

    // Input numbers for the first set
    for (int i = 0; i < n1; i++) {
        printf("Eisagete ton %d arithmo sto prwto set: ", i + 1);
        while (scanf("%f", &numbers1[i]) != 1) {
            printf("Parakalw eisagete valid number.\n");
            clear_input_buffer();
        }
    }

    // Input second set size
    printf("Posous arithmous thelete na eisagete sto deytero set? ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (is_valid_number(input)) {
            n2 = atoi(input);
            if (n2 > 0) break;
        }
        printf("Parakalw eisagete valid number (positivos arithmos) gia to deytero set: ");
    }

    // Dynamically allocate memory for the second set
    float *numbers2 = (float *)malloc(n2 * sizeof(float));
    if (numbers2 == NULL) {
        handle_error("Memory allocation failed.");
        return;
    }

    // Input numbers for the second set
    for (int i = 0; i < n2; i++) {
        printf("Eisagete ton %d arithmo sto deytero set: ", i + 1);
        while (scanf("%f", &numbers2[i]) != 1) {
            printf("Parakalw eisagete valid number.\n");
            clear_input_buffer();
        }
    }

    // Calculate and display the mean and standard deviation for both sets
    double std_dev1 = calculate_standard_deviation(numbers1, n1);
    double std_dev2 = calculate_standard_deviation(numbers2, n2);
    printf("Tupiki apoklish gia to prwto set: %.2f\n", std_dev1);
    printf("Tupiki apoklish gia to deytero set: %.2f\n", std_dev2);

    // Free dynamically allocated memory
    free(numbers1);
    free(numbers2);
}

// Function to handle errors
void handle_error(const char *message) {
    printf("Sfalma: %s\n", message);
    exit(1);  // Exit the program if there's a critical error
}

// Function to implement apolyth_timh()
void apolyth_timh() {
    float number;
    char input[100];

    printf("Eisagete enan arithmo: ");
    
    // Clear input buffer (if needed) to ensure no leftover characters
    while (getchar() != '\n');  // Clear any extra newline from previous input (if any)

    while (1) {
        // Use fgets instead of scanf to allow reading entire input safely
        fgets(input, sizeof(input), stdin);  // Read input as a string
        
        // Check if the input is a valid number (allow spaces and other characters)
        if (is_valid_number(input)) {
            number = atof(input);  // Convert the valid input to a float
            break;  // Exit the loop if valid input is provided
        } else {
            printf("Parakalw eisagete valid number.\n");
        }
    }

    // Calculate and print the absolute value
    printf("I apolyth timh tou arithmou %.2f einai: %.2f\n", number, fabs(number));
}


// Function to implement generate_random_numbers()
void generate_random_numbers() {
    int n;
    char input[100];
    
    printf("Posous tuxaious arithmous thelete na dimiourghsete? ");
    
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (is_valid_number(input)) {
            n = atoi(input);
            break;
        } else {
            printf("Parakalw eisagete valid number.\n");
        }
    }

    srand(time(0));  // Seed the random number generator
    printf("Tuxaioi arithmoi: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", (float)(rand() % 1000) / 100);  // Generate random float between 0 and 9.99
    }
    printf("\n");
}

int main() {
    int choice;
    char continue_program;

    printf("Kalws orisate sto programma ypologismou apolyths timhs!\n");

    do {
        // Display the menu
        printf("\nEpilexte mia leitourgia:\n");
        printf("1. Ypologismos apolyths timhs gia enan arithmo\n");
        printf("2. Ypologismos statistikwn gia polla arithmous\n");
        printf("3. Dimioyrgia tuxaion arithmwn\n");
        printf("4. Sugkrish duo sunolwn arithmwn\n");
        printf("5. Exodos\n");
        printf("Epilogite (1/2/3/4/5): ");
        
        // Clear any leftover characters in the input buffer before reading the choice
        while (getchar() != '\n');  // Flush the buffer of any previous input
        scanf("%d", &choice);  // Read the user's menu choice

        // Execute based on the user's choice
        switch (choice) {
            case 1:
                apolyth_timh();  // Call function for absolute value
                break;
            case 2:
                calculate_and_display_statistics();  // Call function for statistics
                break;
            case 3:
                generate_random_numbers();  // Call function to generate random numbers
                break;
            case 4:
                compare_sets_of_numbers();  // Call function to compare two sets of numbers
                break;
            case 5:
                printf("Eyxaristoume pou xrisimopoihsate to programma!\n");
                break;
            default:
                printf("Lathos epilogi. Parakalw epilexte 1-5.\n");
        }

        // Ask user if they want to do another calculation
        printf("Thelete na kanete allo ypologismo? (Y/N): ");
        
        // Clear the buffer before reading the next character
        while (getchar() != '\n');  // Flush the buffer of any leftover input
        
        // Use a loop to ensure the user only enters 'Y' or 'N'
        do {
            continue_program = getchar();  // Get the user's choice to continue or not
            while (getchar() != '\n');  // Clear any other input left in the buffer

            if (continue_program != 'Y' && continue_program != 'y' && continue_program != 'N' && continue_program != 'n') {
                printf("Lathos eisagwgi. Parakalw eisagete 'Y' h 'N': ");
            }
        } while (continue_program != 'Y' && continue_program != 'y' && continue_program != 'N' && continue_program != 'n');  // Keep asking until valid input is received

    } while (continue_program == 'Y' || continue_program == 'y');  // Repeat if user enters 'Y' or 'y'

    return 0;  // End the program
}
