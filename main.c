#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// For help functions lang
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// For pausing
void waitForEnter() {
    printf("\nPress Enter to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    getchar(); 
}

// For file retrieving
void insertAtEnd(struct Node** head, int data);
void saveToFile(struct Node* head) {
    FILE *file = fopen("list_data.txt", "w");
    if (file == NULL) return;
    struct Node* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d\n", temp->data);
        temp = temp->next;
    }
    fclose(file);
}

void loadFromFile(struct Node** head) {
    FILE *file = fopen("list_data.txt", "r");
    if (file == NULL) return; 
    int data;
    while (fscanf(file, "%d", &data) == 1) {
        insertAtEnd(head, data);
    }
    fclose(file);
}

// FILL IN YOUR ASSIGNED FUNCTIONS BELOW!
// Do not change the function names or parameters.

// PERSON 2: Creation and Traversal
void createList(struct Node** head) {
    // Code dito...
}

void traverse(struct Node* head) {
    // Code dito...
}

// PERSON 3: Adding of New Node at Start and End
void insertAtStart(struct Node** head, int data) {
    // Code dito...
}

void insertAtEnd(struct Node** head, int data) {
    // Code dito...
}

// PERSON 4: Adding New Node Before and After a Node (Target by VALUE)
void insertBefore(struct Node** head, int target, int data) {
    // Code dito...
}

void insertAfter(struct Node* head, int target, int data) {
    // Code dito...
}

// PERSON 5: Deletion of Node at Start and by Value
void deleteAtStart(struct Node** head) {
    // Code dito...
}

void deleteByValue(struct Node** head, int target) {
    // Code dito...
}

// PERSON 6: Deletion Before and After a Node (Target by VALUE)
void deleteBefore(struct Node** head, int target) {
    // Code dito...
}

void deleteAfter(struct Node* head, int target) {
    // Code dito...
}

// Sa buong program na 'to
int main() {
    struct Node* head = NULL;
    int choice, data, target;
    loadFromFile(&head);

    while (1) {
        printf("\n===== Singly Linked List =====\n");
        printf("1. Create a node\n");
        printf("2. Display all nodes\n");
        printf("3. Adding of new node at the start\n");
        printf("4. Adding of new node at the end\n");
        printf("5. Adding new node before a node\n");
        printf("6. Adding new node after a node\n");
        printf("7. Deletion of node at the start\n");
        printf("8. Deletion of node by value\n");
        printf("9. Deletion of node before a node\n");
        printf("10. Deletion of node after a node\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                printf("\n[Success] Node/s created!\n");
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter data to insert at start: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                printf("\n[Success] Node inserted at start!\n");
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("\n[Success] Node inserted at end!\n");
                break;
            case 5:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert before %d: ", target);
                scanf("%d", &data);
                insertBefore(&head, target, data);
                break;
            case 6:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert after %d: ", target);
                scanf("%d", &data);
                insertAfter(head, target, data);
                break;
            case 7:
                deleteAtStart(&head);
                printf("\n[Success] Start node deleted!\n");
                break;
            case 8:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &target);
                deleteByValue(&head, target);
                break;
            case 9:
                printf("Enter the target node value to delete BEFORE it: ");
                scanf("%d", &target);
                deleteBefore(&head, target);
                break;
            case 10:
                printf("Enter the target node value to delete AFTER it: ");
                scanf("%d", &target);
                deleteAfter(head, target);
                break;
            case 11:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\n[Error] Invalid selection.\n");
        }
    }
    return 0;
}
