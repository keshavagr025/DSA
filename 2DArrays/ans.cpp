#include <iostream>
#include <vector>

using namespace std;

// Helper function to calculate sum of digits of a number
int sumofDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    int arr[] = {1, 3, 2};
    int n = sizeof(arr) / sizeof(int);
    int idxSum = -1;

        for(int i=0; i<n; i++){
            if(sumofDigits(arr[i]) == i){
                idxSum = i; 
            }
        }
    cout << idxSum << endl;
}