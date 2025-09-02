#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int n = 0;

// 1. Create Array (Using while loop instead of for)
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size exceeds maximum limit!" << endl;
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    int i = 0;
    while (i < n) {
        cin >> arr[i];
        i++;
    }
    cout << "Array created successfully.\n";
}

// 2. Display Array (Using pointer arithmetic)
void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    int* ptr = arr;
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// 3. Insert Element (Insert at the end if position invalid)
void insert() {
    if (n >= MAX) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    // If position is invalid, insert at the end
    if (pos < 0 || pos > n) {
        cout << "Invalid position! Inserting at the end.\n";
        pos = n;
    }

    // Shift elements right using a while loop
    int i = n;
    while (i > pos) {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}

// 4. Delete Element (Mark deleted element as -1 and then shift - lazy delete)
void deleteElement() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position (0 to " << n - 1 << ") to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    // Mark element to be deleted (lazy deletion)
    arr[pos] = -1;

    // Shift elements left to remove -1 element
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}

// 5. Linear Search (Search from end instead of start)
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int key;
    cout << "Enter value to search: ";
    cin >> key;

    int i = n - 1;
    while (i >= 0) {
        if (arr[i] == key) {
            cout << "Value found at index " << i << endl;
            return;
        }
        i--;
    }
    cout << "Value not found in array.\n";
}

int main() {
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
