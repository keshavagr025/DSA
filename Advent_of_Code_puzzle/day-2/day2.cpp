#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;




bool isInvalidID(unsigned long long num) {
    string s = to_string(num);
    int len = s.length();
    if (len % 2 != 0) return false;
    
    int mid = len / 2;
    string firstHalf = s.substr(0, mid);
    string secondHalf = s.substr(mid);
    
    return firstHalf == secondHalf;
}














unsigned long long solveGiftShop(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return 0;
    }
    
    string line;
    getline(file, line);  // Read the entire line
    file.close();
    
    unsigned long long totalSum = 0;
    stringstream ss(line);
    string range;
    
    // Parse each range separated by comma
    while (getline(ss, range, ',')) {
        // Find the dash separator
        size_t dashPos = range.find('-');
        if (dashPos == string::npos) continue;
        
        // Extract start and end of range
        unsigned long long start = stoull(range.substr(0, dashPos));
        unsigned long long end = stoull(range.substr(dashPos + 1));
        
        // Check each number in the range
        for (unsigned long long num = start; num <= end; num++) {
            if (isInvalidID(num)) {
                totalSum += num;
            }
        }
    }
    
    return totalSum;
}

int main() {
    // Solve actual puzzle
    cout << "=== Solving Advent of Code Day 2 ===" << endl;
    unsigned long long answer = solveGiftShop("input2.txt");
    
    if (answer > 0) {
        cout << "✓ Your Answer: " << answer << endl;
        cout << "\nSubmit this on Advent of Code website!" << endl;
    } else {
        cout << "Error reading input file!" << endl;
    }
    
    return 0;
}