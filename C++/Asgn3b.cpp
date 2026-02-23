#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[50] = "Hello world";
    char words[10][20];
    int wordCount = 0;

    // Split words
    char *token = strtok(str, " ");
    while (token != NULL) {
        strcpy(words[wordCount], token);
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Print in reverse order
    cout << "Reversed Sentence: ";
    for (int i = wordCount - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }

    return 0;
}
