/*
    ### Doubly Linked List ###
    - each element stores an additional pointer to the prev element
    - can be traversed in two directions
    - elements can be added in 4 places
    - takes more space in memory
*/

#include <iostream>
using namespace std;

class DoublyLinkedList {
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        cout << "nullptr <- ";
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << " <-> ";
            } else {
                cout << " -> nullptr";
            }
            curr = curr->next;
        }
    }
};

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
    DoublyLinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);
    list.addTail(4);
    list.addTail(5);
    
    list.print();
    // output: nullptr <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> nullptr

    return 0;
}