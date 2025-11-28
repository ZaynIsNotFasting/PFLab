#include <stdio.h>

struct Team {
    char name[50];
    int scores[20];
    int total_score;
};

int calculate_total(int scores[], int n) {
    if (n <= 0) {
        return 0;
    }
    return scores[n - 1] + calculate_total(scores, n - 1);
}

int main() {
    struct Team teams[50];
    int num_teams, num_rounds, i, j, threshold;

    printf("Enter number of teams: ");
    scanf("%d", &num_teams);

    printf("Enter number of rounds: ");
    scanf("%d", &num_rounds);

    for(i = 0; i < num_teams; i++) {
        printf("\nEnter name of Team %d: ", i + 1);
        scanf("%s", teams[i].name);
        
        printf("Enter scores for %d rounds:\n", num_rounds);
        for(j = 0; j < num_rounds; j++) {
            printf("Round %d: ", j + 1);
            scanf("%d", &teams[i].scores[j]);
        }

        teams[i].total_score = calculate_total(teams[i].scores, num_rounds);
    }

    printf("\nEnter score threshold: ");
    scanf("%d", &threshold);

    printf("\n--- Teams Qualifying (Score > %d) ---\n", threshold);
    for(i = 0; i < num_teams; i++) {
        if(teams[i].total_score > threshold) {
            printf("Team: %s - Total Score: %d\n", teams[i].name, teams[i].total_score);
        }
    }

    return 0;
}