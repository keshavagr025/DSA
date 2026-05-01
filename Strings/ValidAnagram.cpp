#include<iostream>
using namespace std;

bool isAnagram(string s, string t) {

        if(s.length() != t.length())
        {
            cout << "Not Anagram" << endl;
            return false;
        }

        int count[26] = {0};

        for(int i=0; i<s.length(); i++)
        {
            int idx = s[i] - 'a';
            count[idx]++;
        }

        for(int i=0; i<t.length(); i++)
        {
            int idx = t[i] - 'a';
            if(count == 0)
            {
                cout << "Not Anagram" << endl;
                return false;
            }
            count[idx]--;
        }
        
         cout << "Anagram" << endl;
        return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    isAnagram(s,t);


}