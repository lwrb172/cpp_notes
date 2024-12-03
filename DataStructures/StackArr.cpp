/*
    ### Stack implementation using Array ###
    - easy to implement (simplicity)
    - memory is saved as pointers are not involved
    - it is not dynamic (doesn't grow and shrink)
    - wasted space if size is not well estimated
    - total size must be defined beforehand
*/

#include <iostream>
using namespace std;

#define MAX 1000 // stack capacity

class Stack {
    int top;
    int a[MAX];
public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= (MAX-1)) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            a[++top] = x;
            cout << x << " pushed into stack" << endl;
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = a[top--];
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return 0;
        } else {
            int x = a[top];
            return x;
        }
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << stack.pop() << " Popped from stack" << endl;
    cout << "Top element is: " << stack.peek() << endl;
    cout << "Elements present in stack: ";
    while (!stack.isEmpty()) {
        cout << stack.peek() << ' ';
        stack.pop();
    }

    return 0;
}