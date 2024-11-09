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

    printList(head);

    return 0;
}