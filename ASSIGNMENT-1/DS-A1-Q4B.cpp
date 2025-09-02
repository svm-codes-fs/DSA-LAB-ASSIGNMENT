#include <iostream>
using namespace std;

int main() {
    int mat1[10][10], mat2[10][10], product[10][10];
    int rows1, cols1, rows2, cols2;

    // Input dimensions of first matrix
    cout << "Enter rows and columns of first matrix: ";
    cin >> rows1 >> cols1;
    if (rows1 <= 0 || rows1 > 10 || cols1 <= 0 || cols1 > 10) {
        cout << "Invalid size for first matrix! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    // Input dimensions of second matrix
    cout << "Enter rows and columns of second matrix: ";
    cin >> rows2 >> cols2;
    if (rows2 <= 0 || rows2 > 10 || cols2 <= 0 || cols2 > 10) {
        cout << "Invalid size for second matrix! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    // Validate multiplication possibility
    if (cols1 != rows2) {
        cout << "Multiplication not possible! Columns of first matrix must equal rows of second matrix.\n";
        return 0;
    }

    // Input elements of first matrix
    cout << "Enter elements of first matrix:\n";
    for (int r = 0; r < rows1; r++) {
        for (int c = 0; c < cols1; c++) {
            cin >> mat1[r][c];
        }
    }

    // Input elements of second matrix
    cout << "Enter elements of second matrix:\n";
    for (int r = 0; r < rows2; r++) {
        for (int c = 0; c < cols2; c++) {
            cin >> mat2[r][c];
        }
    }

    // Perform multiplication
    for (int r = 0; r < rows1; r++) {
        for (int c = 0; c < cols2; c++) {
            product[r][c] = 0;
            for (int k = 0; k < cols1; k++) {
                product[r][c] += mat1[r][k] * mat2[k][c];
            }
        }
    }

    // Display result
    cout << "Product matrix (first x second):\n";
    for (int r = 0; r < rows1; r++) {
        for (int c = 0; c < cols2; c++) {
            cout << product[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}
