#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node(int value, Node* next, Node* prev) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

Node* convertArr2DLL(int arr[], int size) {
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for (int i = 1; i < size; ++i) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->value << ' ';
        head = head->next;
    }
}

// Node* deleteHead(Node* head) {
//     if (head == NULL || head->next == NULL) return NULL;
//     Node* prev = head;
//     head = head->next;
    
//     head->prev = nullptr;
//     head->next = nullptr;

//     delete prev;
//     return head;
// } 

int main() {
    int arr[4] = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr, 4);
    // deleteHead(head);
    printList(head);

    return 0;
}