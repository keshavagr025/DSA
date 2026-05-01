#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Range {
    long long start, end;
};

// Check if an ID falls in any fresh range
bool isFresh(long long id, vector<Range>& ranges) {
    for (auto& range : ranges) {
        if (id >= range.start && id <= range.end) {
            return true;
        }
    }
    return false;
}

// Trim whitespace from string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

int solveFreshIngredients(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return -1;
    }
    
    vector<Range> freshRanges;
    vector<long long> availableIDs;
    bool readingRanges = true;
    string line;
    
    // Read the file
    while (getline(file, line)) {
        line = trim(line);
        
        // Empty line separates ranges from IDs
        if (line.empty()) {
            readingRanges = false;
            continue;
        }
        
        try {
            if (readingRanges) {
                // Parse range (e.g., "3-5")
                size_t dashPos = line.find('-');
                if (dashPos != string::npos) {
                    string startStr = trim(line.substr(0, dashPos));
                    string endStr = trim(line.substr(dashPos + 1));
                    long long start = stoll(startStr);
                    long long end = stoll(endStr);
                    freshRanges.push_back({start, end});
                }
            } else {
                // Parse single ID
                long long id = stoll(line);
                availableIDs.push_back(id);
            }
        } catch (exception& e) {
            cout << "Error parsing line: '" << line << "' - " << e.what() << endl;
            return -1;
        }
    }
    file.close();
    
    // Count fresh ingredients
    int freshCount = 0;
    
    cout << "Fresh Ranges: " << freshRanges.size() << endl;
    cout << "Available IDs: " << availableIDs.size() << endl << endl;
    
    cout << "Checking freshness..." << endl;
    for (long long id : availableIDs) {
        if (isFresh(id, freshRanges)) {
            freshCount++;
        }
    }
    
    return freshCount;
}

int main() {
    cout << "=== Solving Advent of Code Day 5 ===" << endl << endl;
    
    int answer = solveFreshIngredients("input5.txt");
    
    if (answer != -1) {
        cout << "\n✓ Fresh Ingredient IDs: " << answer << endl;
        cout << "\nSubmit this on Advent of Code website!" << endl;
    }
    
    return 0;
}