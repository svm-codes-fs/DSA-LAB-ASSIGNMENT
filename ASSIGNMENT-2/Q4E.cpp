#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        c = c + 32; 
    }

    cout << "Lowercase character: " << c << endl;
    return 0;
}
