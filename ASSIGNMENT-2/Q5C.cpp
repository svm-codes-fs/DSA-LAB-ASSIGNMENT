#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int *lt = new int[size];
    for (int i = 0; i < size; i++) lt[i] = 0;

    cout << "Enter matrix elements (" << n << "x" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i >= j) {
                int index = (i * (i - 1)) / 2 + (j - 1);
                lt[index] = val;
            }
        }
    }

    cout << "\nLower Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) {
                int index = (i * (i - 1)) / 2 + (j - 1);
                cout << lt[index] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    delete[] lt;
    return 0;
}
