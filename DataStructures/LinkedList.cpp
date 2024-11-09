/*
    ### Linked List ###
    - non continuous collection (elements are random in memory)
    - each element stores its value and pointer to the next element
    - dynamic size
    - efficient insertions/deletions
    - direct access to elements is not allowed
    - slower traversal
    - needs more memory than e.g. array (for pointers)
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->value << endl;
        n = n->next;
    }
}

void insertAtTheFront(Node** head, int value) {
    Node* node = new Node();
    node->value = value;
    node->next = *head;
    *head = node;
}

void insertAtTheEnd(Node** head, int value) {
    Node* node = new Node();
    node->value = value;
    node->next = nullptr;
    if (*head == nullptr) {
        *head = node;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = node;
}

void insertAfter(Node* previous, int value) {
    if (previous == nullptr) {
        cout << "previous cannot be NULL";
        return;
    }
    Node* node = new Node();
    node->value = value;
    node->next = previous->next;
    previous->next = node;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = nullptr;

    insertAtTheFront(&head, -1);
    insertAtTheFront(&head, -2);
    insertAtTheEnd(&head, 4);
    insertAtTheEnd(&head, 5);
    insertAfter(head, -1);
    insertAfter(second, 2);
    printList(head);

    return 0;
}