#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPT_LENGTH 100

int get_category(char c) {
    if (isupper(c)) return 1;
    if (islower(c)) return 2;
    if (isdigit(c)) return 3;
    return 4;
}

double calculate_similarity(const char *pattern, const char *attempt) {
    size_t pattern_len = strlen(pattern);
    size_t attempt_len = strlen(attempt);
    size_t min_len = (pattern_len < attempt_len) ? pattern_len : attempt_len;
    int matches = 0;

    for (size_t i = 0; i < min_len; i++) {
        if (get_category(pattern[i]) == get_category(attempt[i])) {
            matches++;
        }
    }

    if (pattern_len == 0) return 0.0;
    
    return ((double)matches / (double)pattern_len) * 100.0;
}

typedef struct {
    char *password;
    double similarity_score;
    int id;
} Participant;

int main() {
    int num_participants = 0;
    char *pattern_string = NULL;
    char buffer[MAX_ATTEMPT_LENGTH];
    Participant *participants = NULL;
    
    printf("--- Password Pattern Strength Analyzer ---\n");
    printf("Enter the number of participants: ");
    if (scanf("%d", &num_participants) != 1 || num_participants <= 0) {
        printf("Invalid number of participants. Exiting.\n");
        return 1;
    }
    while (getchar() != '\n');

    participants = (Participant *)malloc(num_participants * sizeof(Participant));
    if (participants == NULL) {
        printf("Memory allocation for participants array failed. Exiting.\n");
        return 1;
    }

    printf("\nEnter the secure password pattern (e.g., Aa#91!): ");
    if (fgets(buffer, MAX_ATTEMPT_LENGTH, stdin) == NULL) {
        printf("Error reading pattern. Exiting.\n");
        free(participants);
        return 1;
    }
    size_t pattern_len = strlen(buffer);
    if (pattern_len > 0 && buffer[pattern_len - 1] == '\n') {
        buffer[--pattern_len] = '\0';
    }

    pattern_string = (char *)malloc((pattern_len + 1) * sizeof(char));
    if (pattern_string == NULL) {
        printf("Memory allocation for pattern failed. Exiting.\n");
        free(participants);
        return 1;
    }
    strcpy(pattern_string, buffer);
    printf("Pattern set: %s\n", pattern_string);

    printf("\n--- Inputting and Analyzing Attempts ---\n");
    Participant highest_similarity = {NULL, -1.0, -1};

    for (int i = 0; i < num_participants; i++) {
        printf("Participant %d - Enter password attempt: ", i + 1);
        if (fgets(buffer, MAX_ATTEMPT_LENGTH, stdin) == NULL) {
            printf("Error reading attempt. Stopping analysis.\n");
            num_participants = i;
            break;
        }

        size_t attempt_len = strlen(buffer);
        if (attempt_len > 0 && buffer[attempt_len - 1] == '\n') {
            buffer[--attempt_len] = '\0';
        }

        participants[i].password = (char *)malloc((attempt_len + 1) * sizeof(char));
        if (participants[i].password == NULL) {
            printf("Memory allocation for attempt %d failed. Skipping.\n", i + 1);
            continue;
        }
        strcpy(participants[i].password, buffer);
        participants[i].id = i + 1;

        participants[i].similarity_score = calculate_similarity(pattern_string, participants[i].password);

        if (participants[i].similarity_score > highest_similarity.similarity_score) {
            highest_similarity.similarity_score = participants[i].similarity_score;
            highest_similarity.id = participants[i].id;
        }
    }

    printf("\n--- Analysis Results (Pattern: %s) ---\n", pattern_string);
    for (int i = 0; i < num_participants; i++) {
        if (participants[i].password != NULL) {
            printf("ID %d: \"%s\" -> Similarity: %.2f%%\n", 
                   participants[i].id, 
                   participants[i].password, 
                   participants[i].similarity_score);
        }
    }
    
    if (highest_similarity.id != -1) {
        printf("\n=> BEST MATCH: Participant %d with a score of %.2f%%\n", 
               highest_similarity.id, 
               highest_similarity.similarity_score);
    } else {
        printf("\nNo successful attempts recorded.\n");
    }
    printf("----------------------------------------\n");

    free(pattern_string);
    for (int i = 0; i < num_participants; i++) {
        if (participants[i].password != NULL) {
            free(participants[i].password);
        }
    }
    free(participants);
    printf("Dynamically allocated memory for pattern and attempts freed successfully.\n");

    return 0;
}