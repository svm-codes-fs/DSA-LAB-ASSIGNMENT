#include <iostream>
using namespace std;

void transpose(int mat[][3], int trans[][3]) {
    int m = mat[0][0], n = mat[0][1], t = mat[0][2];
    trans[0][0] = n;  
    trans[0][1] = m;
    trans[0][2] = t;

    int k = 1;
    for (int col = 0; col < n; col++) {
        for (int i = 1; i <= t; i++) {
            if (mat[i][1] == col) {   
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

void display(int mat[][3]) {
    for (int i = 0; i <= mat[0][2]; i++)
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
}

int main() {
    int m, n, t;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> m >> n >> t;

    int mat[20][3], trans[20][3];
    mat[0][0] = m; mat[0][1] = n; mat[0][2] = t;

    cout << "Enter row, col, value of non-zero elements:\n";
    for (int i = 1; i <= t; i++) cin >> mat[i][0] >> mat[i][1] >> mat[i][2];

    cout << "\nOriginal Triplet:\n";
    display(mat);

    transpose(mat, trans);

    cout << "\nTransposed Triplet:\n";
    display(trans);

    return 0;
}
