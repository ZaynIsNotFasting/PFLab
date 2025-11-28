#include <stdio.h>
#include <string.h>

void print_reverse(char *str) {
    if (*str == '\0') {
        return;
    }
    print_reverse(str + 1);
    printf("%c", *str);
}

int is_palindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return is_palindrome(str, start + 1, end - 1);
}

int main() {
    char word[100];
    char choice;

    do {
        printf("\nEnter a word: ");
        scanf("%s", word);

        printf("Reversed: ");
        print_reverse(word);
        printf("\n");

        int len = strlen(word);
        if (is_palindrome(word, 0, len - 1)) {
            printf("The word is a palindrome.\n");
        } else {
            printf("The word is NOT a palindrome.\n");
        }

        printf("Analyze another word? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
