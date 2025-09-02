#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   
    int *sym = new int[size];
    for (int i = 0; i < size; i++) sym[i] = 0;

    cout << "Enter elements of the matrix (" << n << "x" << n << "):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i >= j) { 
                int index = (i * (i - 1)) / 2 + (j - 1);
                sym[index] = val;
            }
        }
    }

    cout << "\nSymmetric Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                int index = (i * (i - 1)) / 2 + (j - 1);
                cout << sym[index] << " ";
            } else {
                int index = (j * (j - 1)) / 2 + (i - 1); 
                cout << sym[index] << " ";
            }
        }
        cout << endl;
    }

    delete[] sym;
    return 0;
}
