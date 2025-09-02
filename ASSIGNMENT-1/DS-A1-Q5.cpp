#include <iostream>
using namespace std;

int main() {
    int grid[10][10];
    int totalRows, totalCols;

    cout << "Enter number of rows: ";
    cin >> totalRows;

    cout << "Enter number of columns: ";
    cin >> totalCols;

    if (totalRows <= 0 || totalRows > 10 || totalCols <= 0 || totalCols > 10) {
        cout << "Invalid size! Rows and columns must be between 1 and 10.\n";
        return 1;
    }

    cout << "Enter the elements of the matrix:\n";
    for (int r = 0; r < totalRows; r++) {
        for (int c = 0; c < totalCols; c++) {
            cin >> grid[r][c];
        }
    }

    cout << "\nSum of each row:\n";
    for (int r = 0; r < totalRows; r++) {
        int sumRow = 0;
        for (int c = 0; c < totalCols; c++) {
            sumRow += grid[r][c];
        }
        cout << "Row " << r + 1 << ": " << sumRow << endl;
    }

    cout << "\nSum of each column:\n";
    for (int c = 0; c < totalCols; c++) {
        int sumCol = 0;
        for (int r = 0; r < totalRows; r++) {
            sumCol += grid[r][c];
        }
        cout << "Column " << c + 1 << ": " << sumCol << endl;
    }

    return 0;
}

