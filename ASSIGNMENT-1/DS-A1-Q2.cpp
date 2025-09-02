#include <iostream>
using namespace std;

int main() {
    int numbers[100], totalCount;

    // Step 1: Get number of elements
    cout << "How many numbers do you want to enter? ";
    cin >> totalCount;
    if (totalCount <= 0 || totalCount > 100) {
        cout << "Invalid input! Enter a number between 1 and 100.\n";
        return 1;
    }

    // Step 2: Read elements
    cout << "Please enter " << totalCount << " numbers:\n";
    int index = 0;
    while (index < totalCount) {
        cin >> numbers[index];
        index++;
    }

    // Step 3: Remove duplicates using separate array
    int uniqueNumbers[100];
    int uniqueCount = 0;

    for (int i = 0; i < totalCount; i++) {
        bool exists = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (numbers[i] == uniqueNumbers[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            uniqueNumbers[uniqueCount] = numbers[i];
            uniqueCount++;
        }
    }

    // Step 4: Copy unique elements back
    for (int k = 0; k < uniqueCount; k++) {
        numbers[k] = uniqueNumbers[k];
    }

    // Step 5: Display the array after removing duplicates
    cout << "\nArray after removing duplicates:\n";
    for (int m = 0; m < uniqueCount; m++) {
        cout << numbers[m] << " ";
    }
    cout << endl;

    return 0;
}
