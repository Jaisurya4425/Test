
#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix 1: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix 2: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    int m1[r1][c1], m2[r2][c2], result[r1][c2];

    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> m1[i][j];

    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> m2[i][j];

    // Optimized multiplication (i-k-j order)
    for (int i = 0; i < r1; i++) {
        for (int k = 0; k < c1; k++) {
            int temp = m1[i][k];
            for (int j = 0; j < c2; j++) {
                result[i][j] += temp * m2[k][j];
            }
        }
    }

    cout << "Result Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
