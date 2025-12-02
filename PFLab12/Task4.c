#include <stdio.h>
#include <stdlib.h>

void calculate_and_display_stats(int *ratings, int n) {
    if (n <= 0) {
        printf("\nNo categories to analyze.\n");
        return;
    }

    long long total_ratings = 0;
    int highest_count = -1;
    int highest_index = -1;

    for (int i = 0; i < n; i++) {
        total_ratings += ratings[i];
        if (ratings[i] > highest_count) {
            highest_count = ratings[i];
            highest_index = i;
        }
    }

    double average_ratings = (double)total_ratings / n;

    printf("\n--- Rating Analysis ---\n");
    printf("Total ratings across all categories: %lld\n", total_ratings);
    printf("Average ratings per category: %.2f\n", average_ratings);
    if (highest_index != -1) {
        printf("Category with the highest rating count: %d (Count: %d)\n", highest_index, highest_count);
    }
    printf("-----------------------\n");
}

void update_category_rating(int *ratings, int n) {
    int index_to_update;
    int new_count;

    printf("\nEnter category index to update (0 to %d): ", n - 1);
    if (scanf("%d", &index_to_update) != 1 || index_to_update < 0 || index_to_update >= n) {
        printf("Invalid category index. Update canceled.\n");
        while(getchar() != '\n');
        return;
    }

    printf("Enter new rating count for Category %d: ", index_to_update);
    if (scanf("%d", &new_count) != 1 || new_count < 0) {
        printf("Invalid count. Update canceled.\n");
        while(getchar() != '\n');
        return;
    }

    ratings[index_to_update] = new_count;
    printf("Rating count for Category %d updated to %d.\n", index_to_update, new_count);
}

void run_menu(int *ratings, int n) {
    int choice;
    
    do {
        printf("\n\n--- Movie Rating Menu ---\n");
        printf("1. Display current rating counts\n");
        printf("2. Show analysis (Total, Avg, Highest)\n");
        printf("3. Update rating count for a category\n");
        printf("4. Exit and free memory\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nCurrent Rating Counts:\n");
                for (int i = 0; i < n; i++) {
                    printf("Category %d: %d\n", i, ratings[i]);
                }
                break;
            case 2:
                calculate_and_display_stats(ratings, n);
                break;
            case 3:
                update_category_rating(ratings, n);
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
    int *ratings_array = NULL;

    printf("Welcome to the Movie Rating Analyzer.\n");

    printf("Enter the number of movie categories: ");
    if (scanf("%d", &num_categories) != 1 || num_categories <= 0) {
        printf("Invalid number of categories. Exiting.\n");
        return 1;
    }

    ratings_array = (int *)malloc(num_categories * sizeof(int));
    if (ratings_array == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Memory successfully allocated for %d categories.\n", num_categories);
    printf("--- Initial Rating Entry ---\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Enter rating count for Category %d: ", i);
        if (scanf("%d", &ratings_array[i]) != 1 || ratings_array[i] < 0) {
            printf("Invalid count. Setting to 0.\n");
            ratings_array[i] = 0;
            while(getchar() != '\n');
        }
    }

    run_menu(ratings_array, num_categories);

    free(ratings_array);
    printf("Dynamically allocated memory freed successfully.\n");
    
    return 0;
}