#include <stdio.h>
#include <stdlib.h>

void display_stats(int *stock, int n) {
    if (n <= 0) {
        printf("\nNo categories to analyze.\n");
        return;
    }

    long long total_stock = 0;
    int lowest_stock = stock[0];
    int lowest_index = 0;

    for (int i = 0; i < n; i++) {
        total_stock += stock[i];
        if (stock[i] < lowest_stock) {
            lowest_stock = stock[i];
            lowest_index = i;
        }
    }

    double average_stock = (double)total_stock / n;

    printf("\n--- Stock Analysis ---\n");
    printf("Total stock: %lld\n", total_stock);
    printf("Average stock per category: %.2f\n", average_stock);
    printf("Category index with the lowest stock: %d (Quantity: %d)\n", lowest_index, lowest_stock);
    printf("----------------------\n");
}

void update_stock(int *stock, int n) {
    int index_to_update;
    int new_quantity;

    printf("\nEnter category index to update (0 to %d): ", n - 1);
    if (scanf("%d", &index_to_update) != 1 || index_to_update < 0 || index_to_update >= n) {
        printf("Invalid category index. Update canceled.\n");
        while(getchar() != '\n');
        return;
    }

    printf("Enter new stock quantity for Category %d: ", index_to_update);
    if (scanf("%d", &new_quantity) != 1 || new_quantity < 0) {
        printf("Invalid quantity. Update canceled.\n");
        while(getchar() != '\n');
        return;
    }

    stock[index_to_update] = new_quantity;
    printf("Stock for Category %d updated to %d.\n", index_to_update, new_quantity);
}

void run_menu(int *stock, int n) {
    int choice;
    
    do {
        printf("\n\n--- Bookstore Stock Menu ---\n");
        printf("1. Display current stock levels\n");
        printf("2. Show statistics (Total, Avg, Lowest)\n");
        printf("3. Update stock for a category\n");
        printf("4. Exit and free memory\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nCurrent Stock Levels:\n");
                for (int i = 0; i < n; i++) {
                    printf("Category %d: %d\n", i, stock[i]);
                }
                break;
            case 2:
                display_stats(stock, n);
                break;
            case 3:
                update_stock(stock, n);
                break;
            case 4:
                printf("\nExiting program. Memory will be freed.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 4);
}

int main() {
    int num_categories = 0;
    int *stock_array = NULL;

    printf("Welcome to the Bookstore Stock Tracker.\n");

    printf("Enter the number of book categories: ");
    if (scanf("%d", &num_categories) != 1 || num_categories <= 0) {
        printf("Invalid number of categories. Exiting.\n");
        return 1;
    }

    stock_array = (int *)malloc(num_categories * sizeof(int));
    if (stock_array == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Memory successfully allocated for %d categories.\n", num_categories);
    printf("--- Initial Stock Entry ---\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Enter stock quantity for Category %d: ", i);
        if (scanf("%d", &stock_array[i]) != 1 || stock_array[i] < 0) {
            printf("Invalid quantity. Setting to 0.\n");
            stock_array[i] = 0;
            while(getchar() != '\n');
        }
    }

    run_menu(stock_array, num_categories);

    free(stock_array);
    printf("Dynamically allocated memory freed successfully.\n");
    
    return 0;
}