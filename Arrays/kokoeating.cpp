#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void findMax(int arr[], int n){
    int maxi = INT16_MIN;

    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int ceilings(int arr[], int n, int h){
    int total = 0;
    for(int i=0; i<n; i++){
        total += ceil(arr[i]/h);
    }

    return total;
}


void kokoEating(int arr[], int n, int h){
    int s = 1, e = findMax(n-1);

    while(s<=e){
        int mid = s + (e-s)/2;
        int totalh = ceilings(arr, n, mid);
        if(totalh <= h){
            e = mid + 1;
        }else{
            s = mid - 1;
        }
    }

    cout << s;
}


int main()
{
    int arr[] = {30,11,23,4,20};
    int n = 5;
    int h = 5;


    kokoEating(arr,5,5);
}