#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int countAdjacentRolls(vector<string>& grid, int x, int y) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].length();
    
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
            if (grid[nx][ny] == '@') {
                count++;
            }
        }
    }
    
    return count;
}

int solvePaperRolls(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return -1;
    }
    
    vector<string> grid;
    string line;
    
    // Read the grid
    while (getline(file, line)) {
        if (!line.empty()) {
            grid.push_back(line);
        }
    }
    file.close();
    
    int accessibleCount = 0;
    int rows = grid.size();
    int cols = grid[0].length();
    
    cout << "Grid size: " << rows << " x " << cols << endl << endl;
    
    // Check each position
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Only check positions with paper rolls
            if (grid[i][j] == '@') {
                int adjacentRolls = countAdjacentRolls(grid, i, j);
                
                // Accessible if fewer than 4 adjacent rolls
                if (adjacentRolls < 4) {
                    accessibleCount++;
                }
            }
        }
    }
    
    return accessibleCount;
}

int main() {
    cout << "=== Solving Advent of Code Day 4 ===" << endl << endl;
    
    // Test with example
    cout << "Testing with example:" << endl;
    int exampleResult = solvePaperRolls("example4.txt");
    cout << "Example accessible rolls: " << exampleResult << " (should be 13)" << endl << endl;
    
    // Solve actual puzzle
    cout << "=== Your Puzzle Solution ===" << endl;
    int answer = solvePaperRolls("input4.txt");
    
    if (answer != -1) {
        cout << "\n✓ Accessible Paper Rolls: " << answer << endl;
        cout << "\nSubmit this on Advent of Code website!" << endl;
    }
    
    return 0;
}