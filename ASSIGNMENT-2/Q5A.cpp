#include <iostream>
using namespace std;

class DiagonalMatrix {
    int *arr;
    int n;

public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n]; 
        for (int i = 0; i < n; i++) arr[i] = 0;
    }

    void set(int i, int j, int val) {
        if (i == j) arr[i - 1] = val; 
    }

    int get(int i, int j) {
        if (i == j) return arr[i - 1];
        else return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) cout << arr[i - 1] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    ~DiagonalMatrix() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    DiagonalMatrix dm(n);

    cout << "Enter diagonal elements: ";
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        dm.set(i, i, val);
    }

    cout << "\nDiagonal Matrix:" << endl;
    dm.display();

    return 0;
}
