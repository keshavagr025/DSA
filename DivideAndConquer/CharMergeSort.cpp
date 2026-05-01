#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintArr(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}

void merge(string arr[], int si, int mid, int ei) {
    vector<string> temp;

    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    for (int i = si, x = 0; i <= ei; i++, x++) {
        arr[i] = temp[x];
    }
}

void mergeSort(string arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

int main() {
    string arr[] = {"sun", "earth", "mars", "jupiter"};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    PrintArr(arr, n);

    return 0;
}
