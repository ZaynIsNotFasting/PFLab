#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FEEDBACK_LENGTH 256

void display_analysis(char **feedback_list, int count, long long total_chars, char *longest_message) {
    printf("\n--- Feedback Analysis ---\n");
    printf("Total number of characters across all entries: %lld\n", total_chars);
    
    if (longest_message != NULL) {
        printf("Longest feedback message (Length: %zu):\n", strlen(longest_message));
        printf(">>> %s\n", longest_message);
    } else {
        printf("No valid feedback entries to determine the longest message.\n");
    }

    printf("\nAll Feedback Entries (%d total):\n", count);
    if (count > 0) {
        for (int i = 0; i < count; i++) {
            printf("[%d]: %s\n", i, feedback_list[i]);
        }
    } else {
        printf("No feedback entries were provided.\n");
    }
    printf("-------------------------\n");
}

int main() {
    int num_entries = 0;
    char **feedback_array = NULL;
    long long total_character_count = 0;
    char *longest_entry_ptr = NULL;
    size_t max_length = 0;

    printf("University Feedback Analysis System\n");
    printf("Enter the number of student feedback entries: ");
    if (scanf("%d", &num_entries) != 1 || num_entries <= 0) {
        printf("Invalid number of entries. Exiting.\n");
        return 1;
    }
    
    while (getchar() != '\n');

    feedback_array = (char **)malloc(num_entries * sizeof(char *));
    if (feedback_array == NULL) {
        printf("Initial memory allocation failed. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < num_entries; i++) {
        char buffer[MAX_FEEDBACK_LENGTH];
        printf("Enter feedback for Entry %d (max %d chars): ", i, MAX_FEEDBACK_LENGTH - 1);
        
        if (fgets(buffer, MAX_FEEDBACK_LENGTH, stdin) == NULL) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }
        
        feedback_array[i] = (char *)malloc((len + 1) * sizeof(char));
        if (feedback_array[i] == NULL) {
            printf("Memory allocation for feedback %d failed. Skipping.\n", i);
            break; 
        }

        strcpy(feedback_array[i], buffer);
        total_character_count += len;

        if (len > max_length) {
            max_length = len;
            longest_entry_ptr = feedback_array[i];
        }
        
        if (i > 0) {
            char **temp = (char **)realloc(feedback_array, (i + 1) * sizeof(char *));
            if (temp == NULL) {
                printf("Error resizing array with realloc. Continuing with current size.\n");
            } else {
                feedback_array = temp;
            }
        }
    }

    display_analysis(feedback_array, num_entries, total_character_count, longest_entry_ptr);

    for (int i = 0; i < num_entries; i++) {
        free(feedback_array[i]);
    }
    free(feedback_array);
    printf("\nAll dynamically allocated memory freed successfully.\n");

    return 0;
}