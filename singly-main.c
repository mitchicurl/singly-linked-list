#include <stdio.h>
#include <stdlib.h>

// Blueprint ng node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // If zero ang value ni user
    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Creation of node
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;

    temp = head;  // temp will help us build the list

    // Create next nodes
    for (i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        temp->next = newNode;  // Link previous node to new node
        temp = newNode;        // Move temp forward
    }

    // Traversal print the values
    printf("\nLinked List Elements:\n");
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
