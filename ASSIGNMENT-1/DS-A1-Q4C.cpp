#include <iostream>
using namespace std;

int main() {
    int original[10][10], transposed[10][10];
    int numRows, numCols;

    cout << "Enter number of rows and columns: ";
    cin >> numRows >> numCols;
    if (numRows <= 0 || numRows > 10 || numCols <= 0 || numCols > 10) {
        cout << "Invalid size! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter the elements of the matrix:\n";
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cin >> original[row][col];
        }
    }

    // Compute transpose
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            transposed[col][row] = original[row][col];
        }
    }

    // Display transpose
    cout << "Transpose of the matrix:\n";
    for (int row = 0; row < numCols; row++) {
        for (int col = 0; col < numRows; col++) {
            cout << transposed[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
