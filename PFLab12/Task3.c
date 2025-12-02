#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 50

int containsDigit(char *str) {
    if (str == NULL) {
        return 0;
    }
    char *p = str;
    while (*p != '\0') {
        if (isdigit(*p)) {
            return 1;
        }
        p++;
    }
    return 0;
}

int main() {
    int num_entries = 0;
    char **username_array = NULL;

    printf("--- Dynamic Username Management System ---\n");
    printf("Enter the number of usernames (N): ");
    if (scanf("%d", &num_entries) != 1 || num_entries <= 0) {
        printf("Invalid number of entries. Exiting.\n");
        return 1;
    }
    
    while (getchar() != '\n');

    username_array = (char **)malloc(num_entries * sizeof(char *));
    if (username_array == NULL) {
        printf("Initial memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Input Usernames:\n");
    for (int i = 0; i < num_entries; i++) {
        char buffer[MAX_USERNAME_LENGTH];
        printf("Username %d (max %d chars): ", i, MAX_USERNAME_LENGTH - 1);
        
        if (fgets(buffer, MAX_USERNAME_LENGTH, stdin) == NULL) {
            printf("Error reading input. Exiting early.\n");
            num_entries = i;
            break;
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }
        
        username_array[i] = (char *)malloc((len + 1) * sizeof(char));
        if (username_array[i] == NULL) {
            printf("Memory allocation for username %d failed. Skipping.\n", i);
            for (int j = 0; j < i; j++) {
                free(username_array[j]);
            }
            free(username_array);
            return 1;
        }

        strcpy(username_array[i], buffer);
    }

    printf("\nFiltering usernames...\n");
    int write_index = 0;
    for (int read_index = 0; read_index < num_entries; read_index++) {
        if (!containsDigit(username_array[read_index])) {
            username_array[write_index] = username_array[read_index];
            write_index++;
        } else {
            free(username_array[read_index]);
        }
    }
    
    int valid_count = write_index;

    char **temp_realloc = (char **)realloc(username_array, valid_count * sizeof(char *));
    if (temp_realloc != NULL) {
        username_array = temp_realloc;
    }

    printf("\n--- Valid Usernames (Alphabetic Only) ---\n");
    if (valid_count == 0) {
        printf("No valid usernames remained after filtering.\n");
    } else {
        for (int i = 0; i < valid_count; i++) {
            printf("[%d]: %s\n", i, username_array[i]);
        }
    }
    printf("----------------------------------------\n");

    for (int i = 0; i < valid_count; i++) {
        free(username_array[i]);
    }
    free(username_array);
    printf("\nAll dynamically allocated memory freed successfully.\n");

    return 0;
}