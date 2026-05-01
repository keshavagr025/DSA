#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std; 

void cowsAndBulls(string secret, string guess){

int bulls=0, cows=0;

        unordered_map<char, int> m1, m2;

        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }

        for(auto it : m1){
            
            if(m2.find(it.first) != m2.end()){
                cows += min(it.second, m2[it.first]);
            }
        }

        string ans = to_string(bulls) + "A" + to_string(cows) + "B";

       cout << "Answer is = " << ans << endl; 
}

int main()
{
    string secret = "1807";
    string guess  = "7810";

    cowsAndBulls(secret, guess);
}