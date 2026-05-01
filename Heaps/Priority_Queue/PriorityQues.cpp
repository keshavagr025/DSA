#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){

    priority_queue<string, vector<string>,greater<string>> q;

    q.push("app");
    q.push("cpp");
    q.push("python");
    q.push("keshav ");

    while(!q.empty()){
        // They gives as at desecnding order 
        cout << "Top = " << q.top() << endl;
        q.pop();
    }
    
}