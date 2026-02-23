#include <iostream>
using namespace std;

int main() {
    char str1[50] = "Programming";
    char str2[50] = "is awesome";

    
    char result[100];

    char *p1 = str1;
    char *p2 = str2;
    char *p = result;

    // Copy str1 to result
    while (*p1 != '\0') {
        *p = *p1;
        p++;
        p1++;
    }

    // Add space
    *p = ' ';
    p++;

    // Copy str2 to result
    while (*p2 != '\0') {
        *p = *p2;
        p++;
        p2++;
    }

    *p = '\0';  // null terminate

    cout << "Concatenated String: " << result << endl;

    return 0;
}
