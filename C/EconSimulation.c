//Explanation of the Code:
//Product Structure: We define a Product struct to store key information about products, such as price, cost, demand, output, elasticity, and externality.

//Linear Programming for Optimization:

//The optimizeResourcesWithLP function uses the GLPK library to perform linear programming optimization. It maximizes profit based on the available resource constraint.
//Dynamic Pricing: The dynamicPricing function adjusts product prices based on demand elasticity (a simple model of supply and demand).

//Profit Calculation: The calculateProfit function calculates profit for each product by considering its price, cost, and output.

//Externality Calculation: The calculateExternalities function models the externality effect of each product (negative or positive), influencing the market's social cost.

//Monte Carlo Simulation: The monteCarloSimulation function runs simple simulations with random demand fluctuations, providing insights into potential demand shifts.

//Market Equilibrium: The marketEquilibrium function checks if the market is in equilibrium for each product (comparing supply to demand).

//Resource Allocation Optimization: The resourceAllocationOptimization function is a placeholder for future optimization algorithms (currently using simple efficiency metrics).

//How to Compile and Run:
//Install GLPK:

//On Linux/macOS, you can install GLPK via the terminal:
//sudo apt-get install glpk-utils (for Ubuntu) or brew install glpk (for macOS).
//Compile:

//bash
//Αντιγραφή κώδικα
//gcc -o economic_simulation economic_simulation.c -lglpk
//Run:

//bash
//Αντιγραφή κώδικα
//./economic_simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glpk.h>

#define NUM_PRODUCTS 3

typedef struct {
    char name[50];
    int price;
    int cost;
    int output;
    int demand;
    float elasticity;
    int externality;
    int resource_usage;  // Example: resources used per unit of production
} Product;

void optimizeResourcesWithLP(Product *products) {
    glp_prob *lp;
    lp = glp_create_prob();
    glp_set_prob_name(lp, "Maximize Profit");
    glp_set_obj_dir(lp, GLP_MAX);

    // Variables (e.g., resources for products)
    glp_add_cols(lp, NUM_PRODUCTS);
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        glp_set_col_name(lp, i + 1, products[i].name);
        glp_set_col_bnds(lp, i + 1, GLP_LO, 0.0, 0.0);  // Products >= 0
        glp_set_obj_coef(lp, i + 1, products[i].price - products[i].cost);  // Profit per unit
    }

    // Constraints (e.g., resources available)
    glp_add_rows(lp, 1);
    glp_set_row_name(lp, 1, "Resource Constraint");
    glp_set_row_bnds(lp, 1, GLP_UP, 0.0, 100.0); // Resource limit

    // Define constraints matrix (e.g., labor and capital usage)
    int ia[4] = {0, 1, 2, 3};  // Row indices
    int ja[4] = {0, 1, 2, 3};  // Column indices
    double ar[4] = {0.0, 1.0, 1.0, 1.0};  // Resource usage for each product
    glp_load_matrix(lp, 3, ia, ja, ar);

    // Solve LP problem
    glp_simplex(lp, NULL);

    // Get results
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        products[i].output = glp_get_col_prim(lp, i + 1);
        printf("%s Production Output: %.2f units\n", products[i].name, products[i].output);
    }

    glp_delete_prob(lp);
}

void dynamicPricing(Product *product) {
    // Apply elasticity to calculate new price based on demand
    float price_change = product->elasticity * (product->demand / 100.0);
    product->price = product->price + price_change;
    printf("Adjusted price for %s: $%.2f\n", product->name, product->price);
}

void calculateProfit(Product *product) {
    float profit = (product->price - product->cost) * product->output;
    printf("Profit for %s: $%.2f\n", product->name, profit);
}

void calculateExternalities(Product *product) {
    // Externality is a simple value added/subtracted from profit
    int external_impact = product->externality * product->output;
    printf("Externality impact for %s: %d\n", product->name, external_impact);
}

void monteCarloSimulation(Product *products, int num_simulations) {
    srand(time(NULL));
    for (int i = 0; i < num_simulations; i++) {
        printf("Simulation %d:\n", i + 1);
        for (int j = 0; j < NUM_PRODUCTS; j++) {
            int simulated_demand = products[j].demand + (rand() % 20 - 10);  // Random fluctuation
            printf("Simulated demand for %s: %d units\n", products[j].name, simulated_demand);
        }
    }
}

void marketEquilibrium(Product *products) {
    printf("\nChecking market equilibrium:\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        if (products[i].output > products[i].demand) {
            printf("%s: Surplus in the market. Excess production: %d units\n", products[i].name, products[i].output - products[i].demand);
        } else if (products[i].output < products[i].demand) {
            printf("%s: Shortage in the market. Deficit in production: %d units\n", products[i].name, products[i].demand - products[i].output);
        } else {
            printf("%s: Market is in equilibrium.\n", products[i].name);
        }
    }
}

void resourceAllocationOptimization(Product *products) {
    printf("\nOptimizing resource allocation:\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        // Here we could implement a more complex optimization method, e.g., using a greedy approach
        int efficiency = products[i].output / products[i].resource_usage;
        printf("%s: Efficiency of producing product: %d units per resource\n", products[i].name, efficiency);
    }
}

int main() {
    Product products[NUM_PRODUCTS] = {
        {"Product A", 50, 30, 0, 200, -0.5, -2, 5},
        {"Product B", 70, 40, 0, 150, -0.3, 5, 3},
        {"Product C", 90, 60, 0, 100, -0.7, 0, 6}
    };

    int inflation_rate = 0;
    printf("Enter the annual inflation rate (as percentage, e.g., 2 for 2%%): ");
    scanf("%d", &inflation_rate);

    // Apply inflation to prices
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        products[i].price *= (1 + inflation_rate / 100.0);
    }

    // Simulate dynamic pricing and calculate profits
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        dynamicPricing(&products[i]);
        calculateProfit(&products[i]);
        calculateExternalities(&products[i]);
    }

    // Resource allocation optimization using LP
    optimizeResourcesWithLP(products);

    // Scenario analysis using Monte Carlo
    monteCarloSimulation(products, 5);

    // Check market equilibrium for each product
    marketEquilibrium(products);

    // Optimizing resource allocation efficiency
    resourceAllocationOptimization(products);

    return 0;
}

