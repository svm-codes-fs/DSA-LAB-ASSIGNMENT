#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;


int applyOperation(int val1, int val2, char op) {
    switch (op) {
        case '^': return pow(val1, val2);
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        default:  return 0;
    }
}


int evaluatePostfix(const string &expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else if (ch != ' ') {   
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            st.push(applyOperation(val1, val2, ch));
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    cout << "Postfix Expression: " << postfix << endl;
    cout << " Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}
