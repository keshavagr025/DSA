#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

// I using unordered map the pair of unqine + value

// unique is element and value is freq of element how many times are occurs

void majorityThree(vector<int> ans){
    int n = ans.size();

    unordered_map<int, int> m;

    for(int i=0; i<n; i++){
        if(m.count[ans[i]]){
            m[ans[i]]++;
        }else{
            m[ans[i]] = 1;  
        }
    }

    vector<int> of;

    for(pair<int, int> p : m){
        if(p.second > n/3){
            of.push_back(p.first);
        }
    }

    return of;
}

void majorityTwo(vector<int> ans){
    int n = ans.size();

    unordered_map<int, int> m;

    for(int i=0; i<n; i++){
        if(m.count[ans[i]]){
            m[ans[i]]++;
        }else{
            m[ans[i]] = 1;
        }
    }

   int fin = 0;

    for(pair<int, int> p : m){
        if(p.second > n/3){
            fin = p.first;
        }
    }

    return fin;
}
