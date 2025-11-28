#include <stdio.h>

typedef struct {
    char name[50];
    int id;
    int days;
} Employee;

int total_attendance(Employee arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n-1].days + total_attendance(arr, n-1);
}

void check_attendance(Employee arr[], int n, int min) {
    int i;
    printf("\nEmployees with less than %d days:\n", min);
    for(i=0; i<n; i++) {
        if(arr[i].days < min) {
            printf("%s (ID: %d) - %d days\n", arr[i].name, arr[i].id, arr[i].days);
        }
    }
}

int main() {
    int n, i, min;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    
    Employee list[n];
    
    for(i=0; i<n; i++) {
        printf("Enter details for Employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", list[i].name);
        printf("ID: ");
        scanf("%d", &list[i].id);
        printf("Days Present: ");
        scanf("%d", &list[i].days);
    }
    
    int total = total_attendance(list, n);
    printf("\nTotal attendance of all employees: %d\n", total);
    
    printf("Enter minimum required days: ");
    scanf("%d", &min);
    check_attendance(list, n, min);
    
    return 0;
}
