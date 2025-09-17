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

    // Confirm size
    cout << "Array size: " << roulettes.size() << endl;

    // Find target
    int target = 3;
    array<int, SIZE>::iterator it;
    it = find(roulettes.begin(), roulettes.end(), target);
    if (it != roulettes.end()) {
        cout << "Target " << target << " found at index " << it - roulettes.begin() << "." << endl;
    } else {
        cout << "Target " << target << " not found." << endl;
    }

    // Find max
    int max = *max_element(roulettes.begin(), roulettes.end());
    cout << "Max value: " << max << endl;

    // Sort in place
    sort(roulettes.begin(), roulettes.end());
    cout << "Sorted array:" << endl;
    printArray(roulettes);

    // Double check max using end of sorted array
    cout << "Max value (double check): " << roulettes.back() << endl;

    // array of SIZE 1s
    array<int, SIZE> ones;
    ones.fill(1);
    cout << "Array of 1s:" << endl;
    printArray(ones);

    // 2-d array
    array< array<int, SIZE>, 2> twoD;
    twoD[0] = roulettes;
    twoD[1] = ones;
    cout << "Last row of 2-D array" << endl;
    cout << twoD[0][SIZE-1] << " " << twoD[1][SIZE-1] << endl;

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
    // - arr: array to print (pass by reference, const)

    for (const int& i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return;
}