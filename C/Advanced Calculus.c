#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <complex.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1000
#define MAX_FUNC_LENGTH 10
#define MAX_VARS 100
#define MAX_HISTORY 100

// Variable structure
typedef struct {
    char name[50];
    double value;
} Variable;

typedef struct {
    double results[MAX_HISTORY];
    int current_index;
} History;

// Global Variables
Variable variables[MAX_VARS];
int var_count = 0;
History history = {{0}, 0};

// Function Prototypes
int find_variable_index(const char *var_name, Variable variables[], int var_count);
double get_variable_value(const char *var_name, Variable variables[], int var_count);
int set_variable_value(const char *var_name, double value, Variable variables[], int *var_count);
void log_history(const char *expression, double result);
void debug_print_expression(const char *expression);
double convert_length(double value, const char *from_unit, const char *to_unit);
double convert_temperature(double value, const char *from_unit, const char *to_unit);
double complex complex_add(double complex a, double complex b);
double complex complex_sub(double complex a, double complex b);
double complex complex_mul(double complex a, double complex b);
double complex complex_div(double complex a, double complex b);
int handle_error(const char *message);
double apply_function(const char *func, double operand);
int parse_and_evaluate(const char *expression);
void undo_last_action();
void *parallel_computation(void *data);

// Function to parse complex numbers from strings like "(2 + 3i)"
double complex parse_complex(const char *expr) {
    double real = 0.0, imag = 0.0;
    char sign = '+';

    // Remove leading and trailing spaces
    while (*expr == ' ') expr++;
    // Check if it starts with '(' and ends with ')'
    if (*expr == '(') expr++; // skip '('
    const char *end = strchr(expr, ')');
    if (end == NULL) {
        handle_error("Invalid complex number format: no closing parenthesis.");
        return 0;
    }

    // Null terminate the string before ')'
    char temp[100];
    strncpy(temp, expr, end - expr);
    temp[end - expr] = '\0';

    // Now parse the real and imaginary parts
    int count = sscanf(temp, "%lf %c %lfi", &real, &sign, &imag);
    if (count == 3) {
        if (sign == '-') {
            imag = -imag;
        }
        return real + imag * I;
    }
    handle_error("Invalid complex number format.");
    return 0;
}

// Main entry function
int main() {
    char expression[MAX_BUFFER_SIZE];

    printf("Enter an expression (or 'exit' to quit): ");
    while (fgets(expression, sizeof(expression), stdin)) {
        expression[strcspn(expression, "\n")] = '\0'; // Remove newline

        if (strcmp(expression, "exit") == 0) {
            break;
        }

        // Handle variable assignment (e.g., a = 5)
        if (strchr(expression, '=') != NULL) {
            char var_name[50];
            double value;
            if (sscanf(expression, "%s = %lf", var_name, &value) == 2) {
                set_variable_value(var_name, value, variables, &var_count);
                printf("Variable '%s' set to %.2f\n", var_name, value);
                log_history(expression, value);
            } else {
                printf("Invalid variable assignment\n");
            }
        }
        else {
            printf("Evaluating: %s\n", expression);
            parse_and_evaluate(expression);
        }

        printf("\nEnter another expression (or 'exit' to quit): ");
    }

    return 0;
}

// Function Definitions

// Find variable index
int find_variable_index(const char *var_name, Variable variables[], int var_count) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(var_name, variables[i].name) == 0) {
            return i;
        }
    }
    return -1; // Variable not found
}

// Get the value of a variable
double get_variable_value(const char *var_name, Variable variables[], int var_count) {
    int idx = find_variable_index(var_name, variables, var_count);
    if (idx != -1) {
        return variables[idx].value;
    }
    handle_error("Variable not found.");
    return 0.0;
}

// Set variable value
int set_variable_value(const char *var_name, double value, Variable variables[], int *var_count) {
    int idx = find_variable_index(var_name, variables, *var_count);
    if (idx != -1) {
        variables[idx].value = value;
        return 0;
    }
    if (*var_count < MAX_VARS) {
        strcpy(variables[*var_count].name, var_name);
        variables[*var_count].value = value;
        (*var_count)++;
        return 0;
    }
    handle_error("Too many variables.");
    return -1;
}

// Log calculation history
void log_history(const char *expression, double result) {
    if (history.current_index < MAX_HISTORY) {
        history.results[history.current_index++] = result;
        printf("Logged: %s = %.2f\n", expression, result);
    } else {
        handle_error("History is full.");
    }
}

// Print debug expression
void debug_print_expression(const char *expression) {
    printf("Debugging Expression: %s\n", expression);
}

// Convert units (length and temperature)
double convert_length(double value, const char *from_unit, const char *to_unit) {
    if (strcmp(from_unit, "meters") == 0 && strcmp(to_unit, "kilometers") == 0) {
        return value / 1000;
    }
    if (strcmp(from_unit, "kilometers") == 0 && strcmp(to_unit, "meters") == 0) {
        return value * 1000;
    }
    return value;
}

double convert_temperature(double value, const char *from_unit, const char *to_unit) {
    if (strcmp(from_unit, "Celsius") == 0 && strcmp(to_unit, "Fahrenheit") == 0) {
        return (value * 9.0 / 5.0) + 32;
    }
    if (strcmp(from_unit, "Fahrenheit") == 0 && strcmp(to_unit, "Celsius") == 0) {
        return (value - 32) * 5.0 / 9.0;
    }
    return value;
}

// Complex number operations
double complex complex_add(double complex a, double complex b) {
    return a + b;
}

double complex complex_sub(double complex a, double complex b) {
    return a - b;
}

double complex complex_mul(double complex a, double complex b) {
    return a * b;
}

double complex complex_div(double complex a, double complex b) {
    if (cabs(b) == 0) {
        handle_error("Division by zero for complex numbers.");
        return 0;
    }
    return a / b;
}

// Apply mathematical function (sin, log, sqrt, etc.)
double apply_function(const char *func, double operand) {
    if (strcmp(func, "sin") == 0) return sin(operand);
    if (strcmp(func, "cos") == 0) return cos(operand);
    if (strcmp(func, "tan") == 0) return tan(operand);
    if (strcmp(func, "log") == 0) return log(operand);
    if (strcmp(func, "sqrt") == 0) return sqrt(operand);
    if (strcmp(func, "exp") == 0) return exp(operand);
    if (strcmp(func, "abs") == 0) return fabs(operand);
    if (strcmp(func, "log10") == 0) return log10(operand);
    handle_error("Unknown function.");
    return 0;
}

// Parse and evaluate expression (basic)
int parse_and_evaluate(const char *expression) {
    if (strchr(expression, 'i') != NULL) {
        // Split the input expression into two complex numbers if possible
        double complex num1, num2;
        char op;
        int result = sscanf(expression, "(%lf + %lfi) %c (%lf + %lfi)", 
                             &num1, &op, &num2);
        if (result == 3) {
            double complex res;
            if (op == '+') {
                res = complex_add(num1, num2);
            } else if (op == '-') {
                res = complex_sub(num1, num2);
            } else if (op == '*') {
                res = complex_mul(num1, num2);
            } else if (op == '/') {
                res = complex_div(num1, num2);
            }
            printf("Result: %.2f + %.2fi\n", creal(res), cimag(res));
            log_history(expression, creal(res)); // Log only the real part for now
        }
    } else {
        // Handle normal numbers here
        double result = atof(expression);  // Example: directly converting the expression
        printf("Result: %.6f\n", result);
        log_history(expression, result);
    }

    return 0;
}

// Undo last action (remove from history)
void undo_last_action() {
    if (history.current_index > 0) {
        history.current_index--;
        printf("Undo: Last action undone.\n");
    } else {
        printf("No actions to undo.\n");
    }
}

// Parallel computation example (multi-threading)
void *parallel_computation(void *data) {
    double *val = (double *)data;
    *val = *val * 2;  // Example computation: doubling the value
    printf("Parallel computation result: %.2f\n", *val);
    return NULL;
}

// Error handler
int handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    return -1;
}
