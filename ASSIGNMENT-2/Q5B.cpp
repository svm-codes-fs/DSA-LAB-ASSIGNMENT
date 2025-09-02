#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int size = 3 * n - 2;
    int *td = new int[size];  // only store non-zeros
    for (int i = 0; i < size; i++) td[i] = 0;

    cout << "Enter matrix elements (" << n << "x" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i - j == 1) td[i - 1] = val;         
            else if (i - j == 0) td[n + i - 1] = val; 
            else if (i - j == -1) td[2 * n + i - 2] = val;
        }
    }

    cout << "\nTri-diagonal Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j == 1) cout << td[i - 1] << " ";
            else if (i - j == 0) cout << td[n + i - 1] << " ";
            else if (i - j == -1) cout << td[2 * n + i - 2] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }

    delete[] td;
    return 0;
}
