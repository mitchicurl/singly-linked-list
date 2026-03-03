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
int n, data, i;
    
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List is empty.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

void traverse(struct Node* head) {
printf("\n--- Current List ---\n");
    if (head == NULL) {
        printf("The list is currently empty.\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d      ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("--------------------\n");
}

// PERSON 3: Adding of New Node at Start and End
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// PERSON 4: Adding New Node Before and After a Node (Target by VALUE)
void insertBefore(struct Node** head, int target, int data) {
    if (*head == NULL) {
        printf("\nError: The list is empty. Target %d not found.\n", target);
        return;
    }

    if ((*head)->data == target) {
        insertAtStart(head, data);
        return;
    }

    struct Node* TravNode = *head;

    while (TravNode->next != NULL && TravNode->next->data != target) {
        TravNode = TravNode->next;
    }

    if (TravNode->next == NULL) {
        printf("\nError: Target value %d not found in the list.\n", target);
    } else {
        struct Node* NewNode = createNode(data);
        NewNode->next = TravNode->next;
        TravNode->next = NewNode;
    }
}

void insertAfter(struct Node* head, int target, int data) {
    if (head == NULL) {
        printf("\nError: The list is empty. Target %d not found.\n", target);
        return;
    }

    struct Node* TravNode = head;

    while (TravNode != NULL && TravNode->data != target) {
        TravNode = TravNode->next;
    }

    if (TravNode == NULL) {
        printf("\nError: Target value %d not found in the list.\n", target);
    } else {
        struct Node* NewNode = createNode(data);
        NewNode->next = TravNode->next;
        TravNode->next = NewNode;
    }
}

// PERSON 5: Deletion of Node at Start and by Value
void deleteAtStart(struct Node** head) {
	if (*head == NULL) {
        printf("\nError: The list is currently empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteByValue(struct Node** head, int target) {
if (*head == NULL) {
        printf("\nError: The list is currently empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* previous = NULL;

    if (current->data == target) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != target) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nError: Value %d not found in the list.\n", target);
        return;
    }

    previous->next = current->next;
    free(current);
}

// PERSON 6: Deletion Before and After a Node (Target by VALUE)
void deleteBefore(struct Node** head, int target) {
if (*head == NULL || (*head)->next == NULL) {
        printf("\nError: List too short to delete 'before'.\n");
        return;
    }

    if ((*head)->data == target) {
        printf("\nError: No node exists before the head (%d).\n", target);
        return;
    }

    if ((*head)->next->data == target) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next->next != NULL && temp->next->next->data != target) {
        temp = temp->next;
    }

    if (temp->next->next == NULL) {
        printf("\nError: Value %d not found.\n", target);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void deleteAfter(struct Node* head, int target) {
if (head == NULL) {
        printf("\nError: List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("\nError: Value %d not found.\n", target);
    } else if (temp->next == NULL) {
        printf("\nError: No node exists after %d (it is the last node).\n", target);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

// List / Choices
int main() {
    struct Node* head = NULL;
    int choice, data, target;
    loadFromFile(&head);

    while (1) {
        system("cls");
        printf("\n===== Singly Linked List by Group 1 =====\n");
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
                waitForEnter();
                break;
            case 2:
                traverse(head);
                waitForEnter();
                break;
            case 3:
                printf("Enter data to insert at start: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                printf("\n[Success] Node inserted at start!\n");
                waitForEnter();
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("\n[Success] Node inserted at end!\n");
                waitForEnter();
                break;
            case 5:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert before %d: ", target);
                scanf("%d", &data);
                insertBefore(&head, target, data);
                waitForEnter();
                break;
            case 6:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert after %d: ", target);
                scanf("%d", &data);
                insertAfter(head, target, data);
                waitForEnter();
                break;
            case 7:
                deleteAtStart(&head);
                printf("\n[Success] Start node deleted!\n");
                waitForEnter();
                break;
            case 8:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &target);
                deleteByValue(&head, target);
                waitForEnter();
                break;
            case 9:
                printf("Enter the target node value to delete BEFORE it: ");
                scanf("%d", &target);
                deleteBefore(&head, target);
                waitForEnter();
                break;
            case 10:
                printf("Enter the target node value to delete AFTER it: ");
                scanf("%d", &target);
                deleteAfter(head, target);
                waitForEnter();
                break;
            case 11:
                printf("\nExiting program...\n");
                saveToFile(head);
                exit(0);
            default:
                printf("\n[Error] Invalid selection.\n");
                waitForEnter();
        }
    }
    return 0;
}
