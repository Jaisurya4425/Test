#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input matrix sizes
    cout << "Enter rows and columns of Matrix 1: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix 2: ";
    cin >> r2 >> c2;

    // Check multiplication condition
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int m1[10][10], m2[10][10], result[10][10] = {0};

    // Input Matrix 1
    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> m1[i][j];

    // Input Matrix 2
    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> m2[i][j];

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Output result
    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
