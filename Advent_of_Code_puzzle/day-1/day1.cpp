#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int solveSafePassword(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return -1;
    }
    
    int position = 50;      // Starting position
    int zeroCount = 0;      // Count of times dial points at 0
    string rotation;
    
    // Read each rotation line by line
    while (getline(file, rotation)) {
        if (rotation.empty()) continue;  // Skip empty lines
        
        char direction = rotation[0];    // 'L' or 'R'
        int distance = stoi(rotation.substr(1));  // Extract number
        
        if (direction == 'L') {
            // Left rotation: subtract distance
            position = (position - distance) % 100;
            // Handle negative modulo in C++
            if (position < 0) position += 100;
        } else {  // direction == 'R'
            // Right rotation: add distance
            position = (position + distance) % 100;
        }
        
        // Check if dial points at 0 after this rotation
        if (position == 0) {
            zeroCount++;
        }
    }
    
    file.close();
    return zeroCount;
}

int main() {
    // Solve actual puzzle
    cout << "=== Solving Advent of Code Day 1 ===" << endl;
    int password = solveSafePassword("input.txt");
    
    if (password != -1) {
        cout << "\n✓ Your Password: " << password << endl;
        cout << "\nNow submit this answer on Advent of Code website!" << endl;
    }
    
    return 0;
}