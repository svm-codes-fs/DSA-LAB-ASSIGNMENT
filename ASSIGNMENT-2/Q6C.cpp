#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};


void transpose(Element a[], int n) {
    cout << "\n(a) Transpose:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].col << " " << a[i].row << " " << a[i].val << endl;
    }
}


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


void multiply(Element a[], int n1, Element b[], int n2, int rowsA, int colsA, int colsB) {
    cout << "\n(c) Multiplication Result:\n";


    int B[10][10] = {0};
    for (int i = 0; i < n2; i++) {
        B[b[i].row][b[i].col] = b[i].val;
    }


    int C[10][10] = {0};

    
    for (int i = 0; i < n1; i++) {
        int r = a[i].row, c = a[i].col, val = a[i].val;
        for (int j = 0; j < colsB; j++) {
            if (B[c][j] != 0) {
                C[r][j] += val * B[c][j];
            }
        }
    }

   
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
    multiply(A, n1, B, n2, 2, 3, 3);  

    return 0;
}
