#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void printUnion(vector<int> arr1, vector<int> arr2){

    unordered_set<int> s;

    for(int el : arr1){
        s.insert(el);
    }

    for(int el : arr2){
        s.insert(el);
    }

    for(int el : s){
        cout << el << " ";
    }

    cout << endl;
}

void printIntersection(vector<int> arr, vector<int> arr1){
    unordered_set<int> s;

    for(int el : arr){
        s.insert(el);
    }


    for(int el : arr1){
        if(s.find(el) != s.end()){
            cout << el << " ";
            s.erase(el);
        }
    }

    cout << endl;
}

int main(){

    vector<int> arr = {7, 3, 9};
    vector<int> arr1 = {6, 3, 9, 2, 9, 4};

    cout << "Union = ";

    printUnion(arr, arr1);

    cout << "Intersection = ";
    printIntersection(arr, arr1);
}