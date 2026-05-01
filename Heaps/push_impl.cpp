#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Heap {
    vector<int> vec;  // max heaps

    public:

    void push(int val){
        
        vec.push_back(val); // O(1)

        int x = vec.size() - 1; // child Index
        int parI = (x-1)/2; // parent Index


        while(parI >= 0 && vec[x] > vec[parI]){ // O(logn)
            swap(vec[x], vec[parI]);

            x = parI;
            parI = (x-1)/2;
        }
    }



    void heapify(int i) { // parent
        
        if(i >= vec.size()){
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxI = i;

        if(l < vec.size() && vec[l] > vec[maxI]){
            maxI = l;
        }

        if(r < vec.size() && vec[r] > vec[maxI]){
            maxI = r;
        }

        swap(vec[i], vec[maxI]);

        if(maxI != i){ // child ke sath swapping ki hai isme 
            heapify(maxI);
        }

    }

    void pop(){

        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();

        heapify(0);
    }

    int top(){
        return vec[0];  // highest priority:
    }

    bool empty(){
        return vec.size() == 0;
    }
};

int main()
{
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);
    

    while(!heap.empty()){
        cout << "Top = " << heap.top() << endl;
        heap.pop();
    }
}