#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main() {
    fstream file;
    string filename, filename2, input, output; cin >> filename >> filename2;

    file.open(filename, ios::in);
    if (!file.is_open()) {
        ofstream creationstream;
        creationstream.open(filename);
        creationstream.close();
    }
    else {
        file >> input;
        char index = input[0];
        int num = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] != index) {
                if (num < 2)
                    output += index;
                else {
                    output += index;
                    output += index;
                    num -= 2;
                    output += to_string(num);
                }
                index = input[i];
                num = 1;
            }
            else
                num++;
        }

        ofstream out(filename2);
        out << output;
        out.close();
    }

    file.close();
}
