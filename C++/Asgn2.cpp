#include <iostream>
using namespace std;

// Function to sort array and return pointer
int* sortArray(int* arr, int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    return arr;
}

int main() {
    int arr[10];

    cout << "Enter 10 integer values:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int* sortedArray = sortArray(arr, 10);

    cout << "Sorted array in ascending order:\n";
    for (int i = 0; i < 10; i++) {
        cout << *(sortedArray + i) << " ";
    }

    return 0;
}

