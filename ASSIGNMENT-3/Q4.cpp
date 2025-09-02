#include <iostream>
#include <stack>
#include <cctype>
using namespace std;


int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:  return 0;
    }
}


bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


bool isOperand(char ch) {
    return isalnum(ch);
}


string infixToPostfix(const string &infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop();
        }
        else if (isOperator(ch)) {
            while (!st.empty() && getPrecedence(st.top()) >= getPrecedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }


    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
