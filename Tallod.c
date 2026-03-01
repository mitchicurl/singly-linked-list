// TALLOD PART
// GAYA GAYA SA GAWA NI SIR KALA MO TALAGA MAGALING EE NO

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *START = NULL;

void insertAtStart (int value) {
    struct Node* Newnode = (struct Node*) malloc(sizeof (struct Node));

    Newnode -> data = value;

    Newnode -> next = NULL;
    Newnode -> next = START;
    START = Newnode;
    Newnode = NULL;

    return 1;
}

void insertAtEnd (int value) {
    struct Node* Newnode = (struct Node*) malloc(sizeof (struct Node));

    Newnode -> data = value;
    Newnode -> next = NULL;

    if (START == NULL) {
        START = Newnode;
        return;
    }
    struct Node* END = START;

    while (END -> next != NULL) {
        END = END -> next;
    }
    END -> next = Newnode;
    Newnode = NULL;
    END = NULL;

    return 1;
}