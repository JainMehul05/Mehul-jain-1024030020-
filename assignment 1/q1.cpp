#include <stdio.h>

#define MAX 100

void create(int arr[], int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);

    printf("Enter elements:\n");
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n) {
    int pos, val;

    if (*n == MAX) {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position (1 to %d): ", *n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1) {
        printf("Invalid Position!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    for (int i = *n - 1; i >= pos - 1; i--)
        arr[i + 1] = arr[i];

    arr[pos - 1] = val;
    (*n)++;

    printf("Element inserted!\n");
}

void deleteElement(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf(" Cannot delete.\n");
        return;
    }

    printf("position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n) {
        printf("Invalid Position!\n");
        return;
    }

    for (int i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    printf("Element deleted!\n");
}

void linearSearch(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }

    int key, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found!\n");
}

int main() {
    int arr[MAX], n = 0, ch;

    do {
        printf("1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(arr, &n); break;
            case 2: display(arr, n); break;
            case 3: insert(arr, &n); break;
            case 4: deleteElement(arr, &n); break;
            case 5: linearSearch(arr, n); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 6);

    return 0;
}
