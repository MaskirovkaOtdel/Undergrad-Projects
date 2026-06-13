#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // For math functions like sqrt and power
#include <string.h> // For strcmp to compare strings

#define FILE_NAME "calc_history.txt"  // File to store history

// Function declarations
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double mod(double a, double b);
double sqrt_func(double a);
void save_history(const char *operation, double result);
int load_history(double results[], char operations[][256], int max_history_size);

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double sub(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double mul(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero isn't possible!\n");
        return NAN;
    }
}

// Function to calculate power
double power(double a, double b) {
    return pow(a, b); // Use the math library's pow function
}

// Function to calculate modulus (only for integers)
double mod(double a, double b) {
    if (b == 0) {
        printf("Error: Modulus by zero isn't possible!\n");
        return NAN;
    }
    return fmod(a, b); // Use fmod for floating-point modulus
}

// Function to calculate square root
double sqrt_func(double a) {
    if (a < 0) {
        printf("Error: Cannot take square root of a negative number!\n");
        return NAN;
    }
    return sqrt(a); // Use the math library's sqrt function
}

// Function to handle user input
double get_input(const char *prompt) {
    double num;
    int valid = 0;

    while (!valid) {
        printf("%s", prompt);
        if (scanf("%lf", &num) == 1) {
            valid = 1; // Successfully read a number
        } else {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the buffer
        }
    }
    return num;
}

// Function to save the history of operations and results to a file
void save_history(const char *operation, double result) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file != NULL) {
        fprintf(file, "%s = %.2lf\n", operation, result);
        fclose(file);
    } else {
        printf("Error: Unable to open file to save history.\n");
    }
}

// Function to load the history from the history file
// It loads up to max_history_size results and operations.
int load_history(double results[], char operations[][256], int max_history_size) {
    FILE *file = fopen(FILE_NAME, "r");
    int history_count = 0;
    if (file != NULL) {
        char line[256];
        // Read all lines and store the operations and results
        while (fgets(line, sizeof(line), file) != NULL && history_count < max_history_size) {
            if (sscanf(line, "%[^\n] = %lf", operations[history_count], &results[history_count]) == 2) {
                history_count++;
            }
        }
        fclose(file);
    }
    return history_count;
}

// Main function
int main() {
    double num1, num2, result;
    char operation[100];  // Store the operation as a string
    double memory = 0.0;  // Store the result in memory for reuse
    double results[10];   // Store past results
    char operations[10][256];  // Store corresponding past operations
    int history_count = 0;  // Number of operations in history
    int continue_calculating = 1;

    // Load past history from the file
    history_count = load_history(results, operations, 10);

    while (continue_calculating) {
        // Display the menu
        printf("\n--- Simple Calculator ---\n");
        printf("Choose an operation:\n");
        printf(" +  : Add\n");
        printf(" -  : Subtract\n");
        printf(" *  : Multiply\n");
        printf(" /  : Divide\n");
        printf(" ^  : Power\n");
        printf(" %% : Modulus\n");
        printf(" sqrt : Square Root\n");
        printf(" m  : Recall Memory\n");
        printf(" h  : Show History\n");
        printf(" c  : Continue from last result\n");
        printf(" s  : Select past result\n");
        printf(" q  : Quit\n");

        // Get the operator from the user (allow multi-character input)
        printf("\nEnter operator: ");
        scanf("%s", operation); // Read the full operator as a string

        // Check for exit condition
        if (strcmp(operation, "q") == 0 || strcmp(operation, "Q") == 0) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // Handle the memory recall
        if (strcmp(operation, "m") == 0) {
            printf("Memory recalled: %.2lf\n", memory);
            continue;
        }

        // Show history
        if (strcmp(operation, "h") == 0) {
            if (history_count == 0) {
                printf("No history available.\n");
            } else {
                printf("\n--- Operation History ---\n");
                for (int i = 0; i < history_count; i++) {
                    printf("%d. %s = %.2lf\n", i + 1, operations[i], results[i]);
                }
            }
            continue;
        }

        // Continue from the last result
        if (strcmp(operation, "c") == 0) {
            if (history_count > 0) {
                printf("Continuing from last result: %.2lf\n", results[history_count - 1]);
                num1 = results[history_count - 1];
                num2 = get_input("Enter the second number: ");
            } else {
                printf("No previous result to continue from.\n");
            }
        } else if (strcmp(operation, "s") == 0) {
            if (history_count == 0) {
                printf("No past results available.\n");
            } else {
                printf("Select a past result (1 to %d):\n", history_count);
                for (int i = 0; i < history_count; i++) {
                    printf("%d. %s = %.2lf\n", i + 1, operations[i], results[i]);
                }
                int choice;
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= history_count) {
                    num1 = results[choice - 1];
                    printf("You selected: %s = %.2lf\n", operations[choice - 1], num1);
                    num2 = get_input("Enter the second number: ");
                } else {
                    printf("Invalid choice. Try again.\n");
                    continue;
                }
            }
        } else if (strcmp(operation, "sqrt") != 0) {
            num1 = get_input("Enter the first number: ");
            num2 = get_input("Enter the second number: ");
        } else {
            num1 = get_input("Enter the number: ");
        }

        // Perform the operation
        if (strcmp(operation, "+") == 0) {
            result = add(num1, num2);
            snprintf(operation, 100, "%.2lf + %.2lf", num1, num2);
            printf("Result: %.2lf\n", result);
        } else if (strcmp(operation, "-") == 0) {
            result = sub(num1, num2);
            snprintf(operation, 100, "%.2lf - %.2lf", num1, num2);
            printf("Result: %.2lf\n", result);
        } else if (strcmp(operation, "*") == 0) {
            result = mul(num1, num2);
            snprintf(operation, 100, "%.2lf * %.2lf", num1, num2);
            printf("Result: %.2lf\n", result);
        } else if (strcmp(operation, "/") == 0) {
            result = divide(num1, num2);
            if (!isnan(result)) {
                snprintf(operation, 100, "%.2lf / %.2lf", num1, num2);
                printf("Result: %.2lf\n", result);
            }
        } else if (strcmp(operation, "^") == 0) {
            result = power(num1, num2);
            snprintf(operation, 100, "%.2lf ^ %.2lf", num1, num2);
            printf("Result: %.2lf\n", result);
        } else if (strcmp(operation, "%%") == 0) {
            result = mod(num1, num2);
            if (!isnan(result)) {
                snprintf(operation, 100, "%.2lf %% %.2lf", num1, num2);
                printf("Result: %.2lf\n", result);
            }
        } else if (strcmp(operation, "sqrt") == 0) {
            result = sqrt_func(num1);
            if (!isnan(result)) {
                snprintf(operation, 100, "sqrt(%.2lf)", num1);
                printf("Result: %.2lf\n", result);
            }
        } else {
            printf("Error: Invalid operator. Please try again.\n");
            continue;
        }

        // Save the history and store the result in memory
        save_history(operation, result);
        memory = result;

        // Load updated history from file
        history_count = load_history(results, operations, 10);

        // Ask the user if they want to continue
        char continue_input;
        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &continue_input); // Leading space to ignore newline
        if (continue_input == 'n' || continue_input == 'N') {
            continue_calculating = 0;
        }
    }

    return 0;
}
