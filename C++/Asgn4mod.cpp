
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("file1_In.txt");
    ofstream fout("file1_out.txt");

    if (!fin || !fout) {
        cout << "File error!" << endl;
        return 1;
    }

    string line;

    while (getline(fin, line)) {
        bool newWord = true;

        for (int i = 0; i < line.length(); i++) {
            if (newWord && isalpha(line[i])) {
                line[i] = toupper(line[i]);
                newWord = false;
            }
            else if (line[i] == ' ' || line[i] == '\t') {
                newWord = true;
            }
        }
        fout << line << endl;
    }

    fin.close();
    fout.close();

    cout << "File processed successfully!" << endl;
    return 0;
}
