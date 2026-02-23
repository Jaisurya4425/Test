
#include <iostream>
using namespace std;

int* sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int* min = arr + i;

        for (int j = i + 1; j < size; j++) {
            if (*(arr + j) < *min) {
                min = arr + j;
            }
        }

        if (min != (arr + i)) {
            int temp = *(arr + i);
            *(arr + i) = *min;
            *min = temp;
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

    cout << "Sorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << *(sortedArray + i) << " ";
    }

    return 0;
}
