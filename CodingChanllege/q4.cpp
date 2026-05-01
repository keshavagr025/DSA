#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Precompute next and previous occurrence for each value
    unordered_map<int, vector<int>> posMap;
    for (int i = 0; i < n; i++) {
        posMap[a[i]].push_back(i);
    }
    
    // Convert map to vector for faster access
    vector<vector<int>> posLists;
    vector<int> valToIdx(2 * n + 1, -1);
    int idx = 0;
    
    for (auto& [val, vec] : posMap) {
        posLists.push_back(vec);
        valToIdx[val + n] = idx++; // offset for negative values
    }
    
    // For each position, find next occurrence of same value
    vector<int> nextSame(n, n);
    vector<int> prevSame(n, -1);
    
    for (const auto& vec : posLists) {
        for (size_t j = 0; j < vec.size(); j++) {
            if (j > 0) prevSame[vec[j]] = vec[j - 1];
            if (j + 1 < vec.size()) nextSame[vec[j]] = vec[j + 1];
        }
    }
    
    int maxLen = 0, bestStart = 0;
    
    // For each position as the end of segment
    for (int r = 0; r < n; r++) {
        // Track the max valid left for this right endpoint
        int minVal = a[r], maxVal = a[r];
        int minPos = r, maxPos = r;
        int lastBad = -1; // last position where condition fails
        
        // Go backwards from r
        for (int l = r; l >= 0; l--) {
            if (a[l] < minVal) {
                minVal = a[l];
                minPos = l;
            } else if (a[l] == minVal && l < minPos) {
                minPos = l;
            }
            
            if (a[l] > maxVal) {
                maxVal = a[l];
                maxPos = l;
            } else if (a[l] == maxVal && l < maxPos) {
                maxPos = l;
            }
            
            // Check if min appears exactly once
            bool minOnce = true;
            if (nextSame[minPos] <= r) minOnce = false;
            if (prevSame[minPos] >= l && prevSame[minPos] != -1) minOnce = false;
            
            // Check if max appears exactly once
            bool maxOnce = true;
            if (nextSame[maxPos] <= r) maxOnce = false;
            if (prevSame[maxPos] >= l && prevSame[maxPos] != -1) maxOnce = false;
            
            if (minOnce && maxOnce) {
                int len = r - l + 1;
                if (len > maxLen || (len == maxLen && l < bestStart)) {
                    maxLen = len;
                    bestStart = l;
                }
            }
            
            // Early break optimization
            if (r - l + 1 <= maxLen) {
                // This segment is not longer than current best
                if (l == r) break;
                l = max(l, r - maxLen + 1);
                continue;
            }
        }
    }
    
    cout << maxLen << " " << bestStart + 1 << "\n";
    
    return 0;
}