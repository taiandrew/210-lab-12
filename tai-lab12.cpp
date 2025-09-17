// COMSC 210 | Lab 12 | Andrew Tai
// IDE: VS Code

#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int SIZE = 50;

// Function prototypes
void readFile(array<string, SIZE>&, int&, string);

// Main
int main() {

    return 0;
}

// Programmer functions
void readFile(array<string, SIZE>& arr, int& size, string filename) {
    // Reads contents of file into array
    // Args:
    // - arr: array to store file contents (pass by reference)
    // - size: number of elements in array
    // - filename: name of file to read from

    // Open file
    ifstream fin(filename);
    if (!fin) {
        cerr << "Input file opening failed.\n";
        return;
    }

    // Read file contents into array
    size = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (getline(fin, arr[i])) {
            ++size;
        } else {
            break;
        }
    }
    fin.close();
    return;
}