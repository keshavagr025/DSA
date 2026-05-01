#include <iostream>
#include <string>
using namespace std;

// int strStr(string haystack, string needle)
// {
//     string check 
//     if(haystack.substr(haystack,needle) != needle)
//     {
//         return -1;
//     }
//     return needle.at(0);
// }

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    int n = needle.length();
    int m = haystack.length();
    string pos = haystack.substr(m,n);
    cout << "Substring = " << pos <<endl;
}