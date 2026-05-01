#include <iostream>
#include<string>
using namespace std;
 
void Permuatation(string str, string ans)
{

    if(str.size() == 0)
    {
        cout << ans << " ";
        return;
    }

    int n = str.size();
    for(int i = 0; i<str.size(); i++)
    {
        char ch = str[i];

        string nextStr = (str.substr(0,i) + str.substr(i+1, n-i-1));

        Permuatation(nextStr, ans + ch);
    }
}
int main()
{
    string str = "abc";
    string ans = "";

    Permuatation(str, ans);
}


// #include <iostream>
// #include <vector>

// using namespace std;

// void PrintArr(vector<int>&v)
// {
//     for(int i=0; i<v.size(); i++){
//         cout << v[i];
//     }
//     cout << endl;
// }

// void Permutations(vector<int> Perms, vector<int> ans){
//     if(Perms.empty()){
//         PrintArr(ans);
//         return;
//     }
//     int n = Perms.size();
//     for(int i=0; i<Perms.size(); i++){
        
//         int ch = Perms[i];

//         vector<int> reaming = Perms;
//         reaming.erase(reaming.begin() + i);

//         vector<int> nextAns = ans;
//         nextAns.push_back(ch);

//         Permutations(reaming, nextAns);
//     }
// }

// int main(){
//     vector<int> Perms = {1,2,3};
//     vector<int> ans;

//     Permutations(Perms, ans);
// }