 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void insertArray(int arr[], int n) {
    for(int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = -1;
}

void deleteArray(int arr[], int n) {
    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
}

struct Node* insertLinkedList(struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = -1;
    newNode->next = head;
    return newNode;
}

struct Node* deleteLinkedList(struct Node* head) {
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main() {
    int n = 5000;
    int arr[6000];

    for(int i = 0; i < n; i++)
        arr[i] = i;

    struct Node* head = NULL;
    for(int i = n - 1; i >= 0; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    clock_t start, end;
    double time;

    start = clock();
    insertArray(arr, n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Array insertion time: %f sec\n", time);

    start = clock();
    head = insertLinkedList(head);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linked list insertion time: %f sec\n", time);

    start = clock();
    deleteArray(arr, n + 1);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Array deletion time: %12f sec\n", time);

    start = clock();
    head = deleteLinkedList(head);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linked list deletion time: %12f sec\n", time);

    return 0;
}