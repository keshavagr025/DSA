#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Trim whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

// Check if a column is blank (for all rows except operator)
bool isBlankColumn(const vector<string>& lines, int col, int H) {
    for (int r = 0; r < H - 1; r++) {
        if (lines[r][col] != ' ') return false;
    }
    return true;
}

long long solveWorksheet(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return -1;
    }

    vector<string> lines;
    string line;

    // Read all lines exactly
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        lines.push_back(line);
    }
    file.close();

    int H = lines.size();
    int W = lines[0].size();
    string ops = lines.back();

    long long grandTotal = 0;

    cout << "Loaded " << H << " rows and " << W << " columns.\n";
    cout << "Beginning problem extraction...\n\n";

    int col = 0;

    while (col < W) {

        // Skip blank separating columns
        while (col < W && isBlankColumn(lines, col, H)) col++;
        if (col >= W) break;

        int start = col;

        // Move until next blank column
        while (col < W && !isBlankColumn(lines, col, H)) col++;
        int end = col - 1;

        // Extract numbers
        vector<long long> values;

        for (int r = 0; r < H - 1; r++) {
            string seg = lines[r].substr(start, end - start + 1);

            // Trim
            seg = trim(seg);
            if (!seg.empty()) {
                values.push_back(stoll(seg));
            }
        }

        // Determine operator
        char op = 0;
        for (int c = start; c <= end; c++) {
            if (ops[c] == '+' || ops[c] == '*') {
                op = ops[c];
                break;
            }
        }

        // Compute result
        long long result = (op == '*') ? 1 : 0;
        for (long long v : values) {
            if (op == '+') result += v;
            else result *= v;
        }

        // cout << "Problem found [" << start << "-" << end << "] ";
        // cout << "Operator: " << op << " → Result = " << result << "\n";

        grandTotal += result;
    }

    return grandTotal;
}

int main() {
    cout << "=== Solving Advent of Code Day 6 ===\n\n";

    long long answer = solveWorksheet("input6.txt");

    if (answer != -1) {
        cout << "\n✓ Grand Total of All Problems: " << answer << endl;
        cout << "\nSubmit this on Advent of Code website!" << endl;
    }

    return 0;
}
