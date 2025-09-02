#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    reverse(s.begin(), s.end()); // STL function
    cout << "Reversed string: " << s << endl;

    return 0;
}
