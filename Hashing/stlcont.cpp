#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;



// int main(){
//     unordered_set<int> s;
//     s.insert(1);
//     s.insert(5);
//     s.insert(6);
//     cout << s.size() << endl;
//     if(s.find(10) != s.end()){
//         cout << "Y" << endl;
//     }else{
//         cout << "N" << endl;
//     }
// }
// int main()
// {
//     unordered_map<string, int> m;
//     m["india"] = 100;
//     m["aisa"] = 160;
//     for(pair<string, int> country : m){
//         cout << country.first << " ," << country.second << endl;
//     }
//     cout << endl;
//     map<string, int> p;
//     p["A"] = 100;
//     p["B"] = 200;
//     for(pair<string, int> apl : p){
//         cout << apl.first << "," << apl.second << endl;
//     }
//     if(p.count("A")){
//         cout << "Yes" << endl;
//     }else{
//         cout << "No" << endl;
//     }
// }