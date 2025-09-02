#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

// Transpose of sparse matrix
void transpose(Element a[], int n) {
    cout << "\n(a) Transpose:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].col << " " << a[i].row << " " << a[i].val << endl;
    }
}

// Addition of two sparse matrices
void add(Element a[], int n1, Element b[], int n2) {
    cout << "\n(b) Addition Result:\n";
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            int sum = a[i].val + b[j].val;
            if (sum != 0) cout << a[i].row << " " << a[i].col << " " << sum << endl;
            i++; j++;
        }
        else if ((a[i].row < b[j].row) ||
                (a[i].row == b[j].row && a[i].col < b[j].col)) {
            cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
            i++;
        }
        else {
            cout << b[j].row << " " << b[j].col << " " << b[j].val << endl;
            j++;
        }
    }
    while (i < n1) cout << a[i].row << " " << a[i].col << " " << a[i++].val << endl;
    while (j < n2) cout << b[j].row << " " << b[j].col << " " << b[j++].val << endl;
}

// Multiplication of two sparse matrices
void multiply(Element a[], int n1, Element b[], int n2, int rowsA, int colsA, int colsB) {
    cout << "\n(c) Multiplication Result:\n";

    // Convert B into normal matrix form for easy access
    int B[10][10] = {0};
    for (int i = 0; i < n2; i++) {
        B[b[i].row][b[i].col] = b[i].val;
    }

    // Result matrix
    int C[10][10] = {0};

    // Multiply
    for (int i = 0; i < n1; i++) {
        int r = a[i].row, c = a[i].col, val = a[i].val;
        for (int j = 0; j < colsB; j++) {
            if (B[c][j] != 0) {
                C[r][j] += val * B[c][j];
            }
        }
    }

    // Print in triplet form
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            if (C[i][j] != 0)
                cout << i << " " << j << " " << C[i][j] << endl;
        }
    }
}

int main() {
    Element A[] = {{0,0,5}, {0,2,8}, {1,1,3}};
    Element B[] = {{0,0,1}, {0,2,2}, {1,1,4}};
    int n1 = 3, n2 = 3;

    transpose(A, n1);
    add(A, n1, B, n2);
    multiply(A, n1, B, n2, 2, 3, 3);  // A(2×3) * B(3×3)

    return 0;
}
