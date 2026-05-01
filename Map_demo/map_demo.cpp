#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    map<int, string> m;

    m[100] = "keshav";
    m[110] = "neha";
    m[101] = "Keshav";

    for(auto it: m){
        cout << "Key = " << it.first << ", Value = " << it.second << endl;
    }
}