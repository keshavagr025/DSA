#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// class Student {
// public:
//    string name;
//    int marks;

//    Student(string name, int marks){
//     this->name = name;
//     this->marks = marks;
//    }    

//    bool operator < (const Student& obj) const {
//     return this->name > obj.name;
//    }
// };

int main(){

    priority_queue<pair<string, int>> pq;

    pq.push(make_pair("aman",55));
    pq.push(make_pair("keshav",98));
    pq.push(make_pair("love",69));
    
    while(!pq.empty()){
        cout << "Top = " << pq.top().first << ", Marks = " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}