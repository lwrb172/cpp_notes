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

    void removeFront() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* tmp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
    }

    void removeEnd() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* tmp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete tmp;
    }

    void clear() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int length() { // make size variable for improved performance
        int result = 0;
        Node* curr = head;
        while (curr != nullptr) {
            result++;
            curr = curr->next;
        }
        return result;
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

int main() {
    DoublyLinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);
    list.push(0); // removed first
    list.addTail(4);
    list.addTail(5);
    list.addTail(6); // removed last

    list.removeEnd();
    list.removeFront();
    cout << list.length() << endl; // 5

    
    list.print();
    // output: nullptr <- 1 <-> 2 <-> 3 <-> 4 <-> 5 -> nullptr

    return 0;
}