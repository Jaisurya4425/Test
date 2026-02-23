
#include <iostream>
using namespace std;

int main() {
    const char str1[] = "Programming";
    const char str2[] = "is awesome.";
    char result[100];

    char *p = result;
    const char *s1 = str1;
    const char *s2 = str2;

    // Copy first string
    while ((*p = *s1) != '\0') {
        p++;
        s1++;
    }

    // Overwrite '\0' with space
    *p++ = ' ';

    // Copy second string
    while ((*p++ = *s2++) != '\0');

    cout << "Concatenated String: " << result << endl;
    return 0;
}
