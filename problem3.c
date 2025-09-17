#include <stdio.h>

int main (){
    int num;
    char ch;

    printf("Enter a number between 65 and 90: ");
    scanf("%d", &num);

    ch = (char) num;

    printf("%d = %c\n", num, ch);
    return 0;
}