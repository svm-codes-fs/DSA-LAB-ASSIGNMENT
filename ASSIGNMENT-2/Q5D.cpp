#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;  // only store upper-triangular part
    int *ut = new int[size];
    for (int i = 0; i < size; i++) ut[i] = 0;

    cout << "Enter matrix elements (" << n << "x" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i <= j) {
                int index = (i - 1) * n - ((i - 2) * (i - 1)) / 2 + (j - i);
                ut[index] = val;
            }
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j) {
                int index = (i - 1) * n - ((i - 2) * (i - 1)) / 2 + (j - i);
                cout << ut[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    delete[] ut;
    return 0;
}
