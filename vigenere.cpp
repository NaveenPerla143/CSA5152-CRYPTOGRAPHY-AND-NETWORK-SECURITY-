#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encipher();
void decipher();

int main() {
    int choice;
    while (1) {
        printf("\n1. Encrypt text");
        printf("\t2. Decrypt text");
        printf("\t3. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            int exit(0);
        } else if (choice == 1) {
            encipher();
        } else if (choice == 2) {
            decipher();
        } else {
            printf("Please enter a valid option");
        }
    }
    return 0;
}

void encipher() {
    unsigned int i, j;
    char input[50], key[10];
    printf("\n\nEnter plain text: ");
    scanf("%s", input);
    printf("\nEnter key value: ");
    scanf("%s", key);
    printf("\nResultant cipher text: ");

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key)) {
            j = 0;
        }
        printf("%c", 65 + ((toupper(input[i]) - 65 + toupper(key[j]) - 65) % 26));
    }
    printf("\n");
}

void decipher() {
    unsigned int i, j;
    char input[50], key[10];
    int value;
    printf("\n\nEnter cipher text: ");
    scanf("%s", input);
    printf("\nEnter key text: ");
    scanf("%s", key);

    printf("\nResultant plain text: ");
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key)) {
            j = 0;
        }
        value = (toupper(input[i]) - 65) - (toupper(key[j]) - 65);
        if (value < 0) {
            value += 26;
        }
        printf("%c", 65 + (value % 26));
    }
    printf("\n");
}
