#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() : top(-1) {}

    bool isFull()  { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(int val) {
        if (isFull())
            cout << "Stack Overflow! Cannot push " << val << endl;
        else
            arr[++top] = val, cout << val << " pushed to stack\n";
    }

    void pop() {
        if (isEmpty())
            cout << "Stack Underflow! Nothing to pop\n";
        else
            cout << arr[top--] << " popped from stack\n";
    }

    void peek() {
        if (isEmpty())
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Stack is empty\n";
        else {
            cout << "Stack: ";
            for (int i = 0; i <= top; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack st;
    int choice, val;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; st.push(val); break;
            case 2: st.pop(); break;
            case 3: st.peek(); break;
            case 4: st.display(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid option!\n";
        }
    }
}
