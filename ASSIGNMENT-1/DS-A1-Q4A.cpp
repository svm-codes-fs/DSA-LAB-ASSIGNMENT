#include <iostream>
using namespace std;

int main() {
    int numbers[100], size;

    cout << "Enter size of array: ";
    cin >> size;
    if (size <= 0 || size > 100) {
        cout << "Invalid array size! Must be between 1 and 100.\n";
        return 1;
    }

    cout << "Enter " << size << " elements:\n";
    int pos = 0;
    while (pos < size) {
        cin >> numbers[pos];
        pos++;
    }

    // Reverse the array by swapping elements from front and back
    for (int front = 0; front < size / 2; front++) {
        int back = size - 1 - front;
        int tempValue = numbers[front];
        numbers[front] = numbers[back];
        numbers[back] = tempValue;
    }

    cout << "Reversed array:\n";
    for (int idx = 0; idx < size; idx++) {
        cout << numbers[idx] << " ";
    }
    cout << endl;

    return 0;
}

