/*
    ### Doubly Linked List ###
    - each element stores an additional pointer to the prev element
    - can be traversed in two directions
    - elements can be added in 4 places
    - takes more space in memory
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* previous;
};

void printForward(Node* head) {
    Node* traverser = head;
    while (traverser != nullptr) {
        cout << traverser->value << endl;
        traverser = traverser->next;
    }
}

void printBackwards(Node* tail) {
    Node* traverser = tail;
    while (traverser != nullptr) {
        cout << traverser->value << endl;
        traverser = traverser->previous;
    }
}

int main() {
    Node* head;
    Node* tail;

    // add 1st node
    Node* node = new Node;
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    
    head = node;
    tail = node;

    // add 2nd node
    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    // add 3rd node
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    // add 4rd node
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    printBackwards(tail);

    return 0;
}