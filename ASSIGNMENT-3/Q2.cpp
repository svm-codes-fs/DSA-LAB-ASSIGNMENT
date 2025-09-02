#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool isFull()  { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(char ch) {
        if (isFull()) cout << "Stack Overflow! Cannot push " << ch << endl;
        else arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop\n";
            return '\0';
        }
        return arr[top--];
    }
};

string reverseString(const string &str) {
    Stack st;
    for (char ch : str) st.push(ch);

    string result;
    while (!st.isEmpty()) result += st.pop();

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = reverseString(input);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << output << endl;

    return 0;
}

