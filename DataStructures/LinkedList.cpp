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

class LinkedList {
    struct Node {
        int data;
        Node* next;
        
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;    
    }

    void clear() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int length() {
        int result = 0;
        Node* curr = head;
        while (curr != nullptr) {
            result++;
            curr = curr->next;
        }
        return result;
    }

    void print() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout << "nullptr" << endl;
    }

    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.print();
    // output: 3 -> 2 -> 1 -> nullptr
    list.clear();

    for(int i = 3; i > 0; i--) {
        list.push(i);
    }
    list.removeFront();
    list.print();
    // output: 2 -> 3 -> nullptr

    cout << "length = " << list.length() << endl; // 2

    return 0;
}