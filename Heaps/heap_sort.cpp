#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

void heapify(int i, vector<int>& arr,int n){
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    int maxIdx = i;

    if( l < n && arr[l] > arr[maxIdx]){
        maxIdx = l;
    }

    
    if( r < n && arr[r] > arr[maxIdx]){
        maxIdx = r;
    }

    if(maxIdx != i){
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);  // n is 2nd step process
    }

}

void heapSort(vector<int> &arr){
    
    int n = arr.size();

    // Build maxHeap
    for(int i = n/2 - 1; i>=0 ; i--){
        heapify(i, arr, n);
    }

    // step 2 taking ele to correct pos

    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main(){
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}