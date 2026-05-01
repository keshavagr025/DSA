#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Find maximum joltage from a single bank
int getMaxJoltage(string bank) {
    int maxJoltage = 0;
    
    // Check ALL pairs of batteries (not just consecutive)
    for (size_t i = 0; i < bank.length(); i++) {
        for (size_t j = i + 1; j < bank.length(); j++) {
            // Get two digits at positions i and j
            int digit1 = bank[i] - '0';
            int digit2 = bank[j] - '0';
            
            // Form 2-digit number (first digit * 10 + second digit)
            int joltage = digit1 * 10 + digit2;
            
            // Update maximum
            maxJoltage = max(maxJoltage, joltage);
        }
    }
    
    return maxJoltage;
}

int solveBatteries(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return -1;
    }
    
    int totalJoltage = 0;
    string bank;
    int lineNum = 0;
    
    // Read each bank line by line
    while (getline(file, bank)) {
        if (bank.empty()) continue;
        
        lineNum++;
        int maxJoltage = getMaxJoltage(bank);
        totalJoltage += maxJoltage;
        
        // Show first few lines as example
        if (lineNum <= 5) {
            cout << "Line " << lineNum << ": " << bank.substr(0, 20) << "... -> Max = " << maxJoltage << endl;
        }
    }
    
    cout << "... (processed " << lineNum << " total lines)" << endl;
    
    file.close();
    return totalJoltage;
}

int main() {
    cout << "=== Solving Advent of Code Day 3 ===" << endl << endl;
    
    // Test example manually
    cout << "Testing examples:" << endl;
    cout << "987654321111111 -> " << getMaxJoltage("987654321111111") << " (should be 98)" << endl;
    cout << "811111111111119 -> " << getMaxJoltage("811111111111119") << " (should be 89)" << endl;
    cout << "234234234234278 -> " << getMaxJoltage("234234234234278") << " (should be 78)" << endl;
    cout << "818181911112111 -> " << getMaxJoltage("818181911112111") << " (should be 92)" << endl;
    cout << endl;
    
    int answer = solveBatteries("input3.txt");
    
    if (answer != -1) {
        cout << "\n✓ Total Output Joltage: " << answer << endl;
        cout << "\nSubmit this on Advent of Code website!" << endl;
    }
    
    return 0;
}