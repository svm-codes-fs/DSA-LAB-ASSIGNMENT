#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool areBracketsBalanced(const string &expr) {
    stack<char> st;

    for (char ch : expr) {

        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }

        else {
            if (st.empty()) return false;

            if ((ch == ')' && st.top() == '(') ||
                (ch == ']' && st.top() == '[') ||
                (ch == '}' && st.top() == '{')) {
                st.pop();
                }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    if (areBracketsBalanced(input))
        cout << "Balanced brackets" << endl;
    else
        cout << "Unbalanced brackets" << endl;

    return 0;
}
