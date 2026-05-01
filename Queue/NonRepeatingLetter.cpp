#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeat(string s)
{
    int freq[26] = {0};
    queue<char> Q;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        Q.push(ch);
        freq[ch - 'a']++;

        while (!Q.empty() && freq[Q.front() - 'a'] > 1)
        {
            Q.pop();
        }

        if (Q.empty())
        {
            cout << "-1\n";
        }
        else
        {
            cout << Q.front() << "\n";
        }
    }
}

int main()
{
    string s = "aabccxb";

    firstNonRepeat(s);
}