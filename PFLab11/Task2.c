#include <stdio.h>

void print_countdown(int days) {
    if (days < 0) {
        return;
    }
    if (days == 0) {
        printf("0 days left - The event is today!\n");
        return;
    }
    
    printf("%d days remaining\n", days);
    print_countdown(days - 1);
}

int main() {
    char event_names[50][100];
    int days_left[50];
    int count, i;

    printf("How many events are there? ");
    scanf("%d", &count);

    for(i = 0; i < count; i++) {
        printf("\nEnter name of event %d: ", i + 1);
        scanf("%s", event_names[i]);
        printf("Enter days remaining for %s: ", event_names[i]);
        scanf("%d", &days_left[i]);
    }

    printf("\n--- Event Countdowns ---\n");

    for(i = 0; i < count; i++) {
        printf("\nEvent: %s\n", event_names[i]);
        print_countdown(days_left[i]);
    }

    return 0;
}