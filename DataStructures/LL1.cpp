#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

Node* convertArr2LL(int arr[], int size) {
    Node* head = new Node(arr[0], nullptr);
    Node* traverser = head;
    for (int i = 1; i < size; ++i) {
        Node* temp = new Node(arr[i], nullptr);
        traverser->next = temp;
        traverser = temp;
    }
    return head;
}

int lengthOfLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

int checkIfPresent(Node* head, int value) {
    Node* temp = head;
    while (temp) { // 1 = true, 0 = false
        if (temp->value == value) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int arr[4] = {2, 5, 8, 7};

    Node* head = convertArr2LL(arr, 4);
    Node* temp = head;
    while (temp) {
        cout << temp->value << ' ';
        temp = temp->next;
    }
    cout << endl;

    cout << lengthOfLL(head) << endl;
    cout << checkIfPresent(head, 5) << endl;
    cout << checkIfPresent(head, 6) << endl;

    return 0;
}