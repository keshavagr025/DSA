// #include <iostream>
// #include <queue>
// #include <vector>
// #include <cmath>
// using namespace std;

// class Car{
//     public:
//     int idx;
//     int distsq;

//     Car(int idx, int distsq){
//         this->idx = idx;
//         this->distsq = distsq;
//     }

//     bool operator < (const Car &obj) const {
//         return this->distsq > obj.distsq;  // min heap
//     }
// };

  
// void nearbyCar(vector<pair<int, int>>pos, int k){
//     vector<int> cars;

//     for(int i=0; i<pos.size(); i++){
//         int distsq = (pos[i].first * pos[i].first ) + (pos[i].second * pos[i].second);

//         cars.push_back(Car(i, distsq));
//     }

//     // priority_queue<Car >pq; 

//     // min heap banane ka first tareeka 
//     // O(nlogn)
//     // for(int i=0; i<cars.size(); i++){
//     //     pq.push(cars[i]);
//     // } 

//     // OR

//     priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

//     for(int i=0; i<k; i++){ //O(k)
//         cout << "Car" << pq.top().idx << endl;
//         pq.pop(); //O(logn)
//     } // O(klogn)
// }

// int main(){
//     vector<pair<int, int>> pos;
//     pos.push_back(make_pair(3,3));
//     pos.push_back(make_pair(5-1));
//     pos.push_back(make_pair(-2,4));

//     int k= 2;

//     nearbyCar(pos, k);
// }


#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class Car {
    public:
    int idx;
    int distsq;

    Car(int idx, int distsq) {
        this->idx = idx;
        this->distsq = distsq;
    }

    bool operator < (const Car &obj) const {
        return this->distsq > obj.distsq;  // min heap
    }
};

void nearbyCar(vector<pair<int, int>> pos, int k) {
    vector<Car> cars;

    for (int i = 0; i < pos.size(); i++) {
        int distsq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distsq));
    }

    // Create min heap with all cars based on distance
    priority_queue<Car> pq(cars.begin(), cars.end());

    for (int i = 0; i < k; i++) {
        cout << "Car = " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));

    int k = 2;

    nearbyCar(pos, k);
}
