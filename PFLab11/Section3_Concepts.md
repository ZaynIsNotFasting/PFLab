# Section 3: Arrays & Strings with Functions

## 1. Passing Arrays to Functions

In C, when you pass an array to a function, it decays into a pointer to its first element. This means you are passing by reference (effectively), and changes in the function affect the original array.

### 1D Arrays

```c
void modifyArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        arr[i] *= 2; // Modifies original array
    }
}
// Call: modifyArray(myArray, 5);
```

### 2D Arrays

For 2D arrays, you must specify the number of columns in the function signature.

```c
void print2D(int arr[][3], int rows) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
// Call: print2D(matrix, 2);
```

## 2. Strings with Functions

Strings are just char arrays terminated by `\0`.

### Passing Strings

```c
void greet(char str[]) { // or char *str
    printf("Hello, %s!", str);
}
```

### Common String Functions (`<string.h>`)

- `strlen(s)`: Length of string (excluding null terminator).
- `strcpy(dest, src)`: Copy src to dest.
- `strcat(dest, src)`: Concatenate src to end of dest.
- `strcmp(s1, s2)`: Compare strings (returns 0 if equal).

### Example: String Processing

```c
int countVowels(char *str) {
    int count = 0;
    for(int i=0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') count++;
    }
    return count;
}
```
