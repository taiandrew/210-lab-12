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
const string FILENAME = "/Users/andrewtai/Desktop/COMSC_210/projects/210-lab-12/roulette.txt";

// Function prototypes
void readFile(array<int, SIZE>& arr, string filename);
void printArray(const array<int, SIZE>& arr);

// Main
int main() {

    // Declare variables
    array<int, SIZE> roulettes;

    // Read file
    readFile(roulettes, FILENAME);
    cout << "Unsorted array:" << endl;
    printArray(roulettes);


    return 0;
}

// Programmer functions
void readFile(array<int, SIZE>& arr, string filename) {
    // Reads contents of file into array
    // Args:
    // - arr: array to store file contents (pass by reference)
    // - filename: name of file to read from

    // Open file
    ifstream fin(filename);
    if (!fin) {
        cerr << "Input file opening failed." << endl;
        return;
    }

    // Read file contents into array
    for (int i = 0; i < SIZE; ++i) {
        if (fin.eof()) break;
        fin >> arr[i];
    }
    fin.close();
    return;
}

void printArray(const array<int, SIZE>& arr) {
    // Prints contents of array
    // Args:
    // - arr: array to print (pass by reference)

    for (const int& item : arr) {
        cout << item << " ";
    }
    cout << endl;
    return;
}