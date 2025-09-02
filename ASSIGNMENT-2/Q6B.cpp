#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void add(Element a[], int n1, Element b[], int n2, Element c[], int &n3) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            int sum = a[i].val + b[j].val;
            if (sum != 0) { // store only non-zero
                c[k++] = {a[i].row, a[i].col, sum};
            }
            i++; j++;
        }
        else if ((a[i].row < b[j].row) ||
                (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
                }
        else {
            c[k++] = b[j++];
        }
    }

    // remaining elements
    while (i < n1) c[k++] = a[i++];
    while (j < n2) c[k++] = b[j++];

    n3 = k; // store size of result
}

// Utility to print triplet
void print(Element arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i].row << " " << arr[i].col << " " << arr[i].val << endl;
}

int main() {
    Element A[] = {{0,0,2}, {0,2,3}, {1,1,4}};
    Element B[] = {{0,0,5}, {1,1,-4}, {2,2,6}};
    Element C[20];
    int n3;

    add(A, 3, B, 3, C, n3);

    cout << "(b) Addition Result:\n";
    print(C, n3);

    return 0;
}
