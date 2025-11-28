#include <stdio.h>
#include <string.h>

struct Gift {
    char name[50];
    char type[30];
    float price;
    int quantity;
};

int main() {
    struct Gift gifts[100];
    int n, i;
    float price_limit;
    int qty_limit;

    printf("Enter the number of gifts: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details for gift %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", gifts[i].name);
        printf("Type: ");
        scanf("%s", gifts[i].type);
        printf("Price: ");
        scanf("%f", &gifts[i].price);
        printf("Quantity: ");
        scanf("%d", &gifts[i].quantity);
    }

    printf("\nEnter price threshold to find expensive gifts: ");
    scanf("%f", &price_limit);

    printf("\nGifts with price greater than %.2f:\n", price_limit);
    for(i = 0; i < n; i++) {
        if(gifts[i].price > price_limit) {
            printf("%s (Type: %s) - Price: %.2f\n", gifts[i].name, gifts[i].type, gifts[i].price);
        }
    }

    printf("\nEnter quantity threshold: ");
    scanf("%d", &qty_limit);

    printf("\nGifts with quantity greater than %d:\n", qty_limit);
    for(i = 0; i < n; i++) {
        if(gifts[i].quantity > qty_limit) {
            printf("%s (Type: %s) - Quantity: %d\n", gifts[i].name, gifts[i].type, gifts[i].quantity);
        }
    }

    return 0;
}