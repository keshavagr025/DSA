#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

// s = "race" , t = "care"

// time comp o(size ke equal) or O(n)

bool validAnangram(string s, string t){

    if(s.size() != t.size()){
        return false;   
    }

    // that loop for store freq of chareac
    unordered_map<char, int> m;
    for(int i=0; i<s.length(); i++){
        if(m.count(s[i])){
            m[s[i]]++;
        }else{
            m[s[i]] = 1;
        }
    }

    // to look t's char in freqs

    for(int i=0; i<t.length(); i++){
        if(m.count(t[i])){
            m[t[i]]--;

            if(m[t[i]] == 0){
                m.erase(t[i]);  
            }
        }else{
            return false;
        }
    }
    return m.size() == 0;
}

int main(){
    string s = "tulip";
    string t = "lipid";

    cout << validAnangram(s, t) << " " << endl;
}