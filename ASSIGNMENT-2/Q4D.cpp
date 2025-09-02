#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // clear input buffer

    char arr[50][50]; // max 50 strings, each max length 49
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin.getline(arr[i], 50);
    }

    // Bubble sort (alphabetical using strcmp)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[50];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
