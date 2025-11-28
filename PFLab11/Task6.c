#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char category[50];
    int quantity;
} Item;

void input_items(Item *ptr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter details for Item %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", (ptr + i)->name);
        printf("Category: ");
        scanf(" %[^\n]s", (ptr + i)->category);
        printf("Quantity: ");
        scanf("%d", &(ptr + i)->quantity);
    }
}

void filter_category(Item *ptr, int n, char *cat) {
    int i, found = 0;
    printf("\nItems in category '%s':\n", cat);
    for (i = 0; i < n; i++) {
        if (strcmp((ptr + i)->category, cat) == 0) {
            printf("%s | %d\n", (ptr + i)->name, (ptr + i)->quantity);
            found = 1;
        }
    }
    if (!found) printf("None found.\n");
}

void filter_quantity(Item *ptr, int n, int min) {
    int i, found = 0;
    printf("\nItems with quantity >= %d:\n", min);
    for (i = 0; i < n; i++) {
        if ((ptr + i)->quantity >= min) {
            printf("%s | %s | %d\n", (ptr + i)->name, (ptr + i)->category, (ptr + i)->quantity);
            found = 1;
        }
    }
    if (!found) printf("None found.\n");
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item inventory[n];
    input_items(inventory, n);

    char cat[50];
    printf("\nEnter category to search: ");
    scanf(" %[^\n]s", cat);
    filter_category(inventory, n, cat);

    int min_q;
    printf("\nEnter minimum quantity: ");
    scanf("%d", &min_q);
    filter_quantity(inventory, n, min_q);

    return 0;
}
