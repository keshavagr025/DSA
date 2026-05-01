#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void mostFreq(string& s)
{
    int freq[256] = {0};
    int firstPos[256];

    fill(firstPos, firstPos + 256, -1);  // Initialize first positions to -1

    int maxDigit = 0, maxLower = 0, maxUpper = 0, maxSpecial = 0;
    char mostFreqDigit = '\0', mostFreqlower = '\0', mostFreqUpper = '\0', mostFreqSpecial = '\0';

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch]++;

        if (firstPos[ch] == -1) {
            firstPos[ch] = i;
        }

        // Check digit
        if (isdigit(ch)) {
            if (freq[ch] > maxDigit || (freq[ch] == maxDigit && firstPos[ch] < firstPos[mostFreqDigit])) {
                maxDigit = freq[ch];
                mostFreqDigit = ch;
            }
        }
        // Check lowercase letter
        else if (islower(ch)) {
            if (freq[ch] > maxLower || (freq[ch] == maxLower && firstPos[ch] < firstPos[mostFreqlower])) {
                maxLower = freq[ch];
                mostFreqlower = ch;
            }
        }
        // Check uppercase letter
        else if (isupper(ch)) {
            if (freq[ch] > maxUpper || (freq[ch] == maxUpper && firstPos[ch] < firstPos[mostFreqUpper])) {
                maxUpper = freq[ch];
                mostFreqUpper = ch;
            }
        }
        // Check special character
        else {
            if (freq[ch] > maxSpecial || (freq[ch] == maxSpecial && firstPos[ch] < firstPos[mostFreqSpecial])) {
                maxSpecial = freq[ch];
                mostFreqSpecial = ch;
            }
        }
    }

    // Output results for the most frequent digit
    if (mostFreqDigit != '\0') {
        cout << "Most frequent digit: " << mostFreqDigit << " at positions: ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == mostFreqDigit) cout << i << " ";
        }
        cout << endl;
    }

    // Output results for the most frequent uppercase letter
    if (mostFreqUpper != '\0') {
        cout << "Most frequent uppercase letter: " << mostFreqUpper << " at positions: ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == mostFreqUpper) cout << i << " ";
        }
        cout << endl;
    }

    // Output results for the most frequent lowercase letter
    if (mostFreqlower != '\0') {
        cout << "Most frequent lowercase letter: " << mostFreqlower << " at positions: ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == mostFreqlower) cout << i << " ";
        }
        cout << endl;
    }

    // Output results for the most frequent special character
    if (mostFreqSpecial != '\0') {
        cout << "Most frequent special character: " << mostFreqSpecial << " at positions: ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == mostFreqSpecial) cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s;
    cout << "Enter the string:" << endl;
    getline(cin, s);
    mostFreq(s);
    return 0;
}
