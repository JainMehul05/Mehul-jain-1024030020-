#include <stdio.h>
#include <string.h>

void concatenate() {
    char s1[200], s2[200];
    printf("Enter first string: ");
    gets(s1);
    printf("Enter second string: ");
    gets(s2);

    int i = 0, j = 0;
    while (s1[i] != '\0') i++;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';

    printf("Concatenated string: %s\n", s1);
}

void reverseString() {
    char str[200], rev[200];
    int len = 0, i, j = 0;

    printf("Enter a string: ");
    gets(str);

    while (str[len] != '\0') len++;

    for (i = len - 1; i >= 0; i--)
        rev[j++] = str[i];

    rev[j] = '\0';
    printf("Reversed string: %s\n", rev);
}

void deleteVowels() {
    char str[200], res[200];
    int i, j = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            continue;
        res[j++] = c;
    }
    res[j] = '\0';
    printf("String without vowels: %s\n", res);
}

void sortStrings() {
    int n, i, j;
    char str[20][100], temp[100];

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
        gets(str[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("Sorted strings:\n");
    for (i = 0; i < n; i++)
        puts(str[i]);
}

void upperToLower() {
    char ch;
    printf("Enter uppercase character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32;

    printf("Lowercase: %c\n", ch);
}

int main() {
    int choice;
    char dummy;

    do {
        printf("1. Concatenate Strings\n");
        printf("2. Reverse String\n");
        printf("3. Delete Vowels\n");
        printf("4. Sort Strings\n");
        printf("5. Uppercase to Lowercase\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: concatenate(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: upperToLower(); break;
            case 6: break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}
