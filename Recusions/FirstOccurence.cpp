#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int FirstOcc(vector<int> arr,  int i ,int target )
{
    if(i == arr.size())
    {
        return -1;
    }
    
     int temp = 0 ;
    if(arr[i] == target)
    {
        temp = i;
        cout << temp << ",";

    }

 
    return FirstOcc(arr , i+1, target);
}
int main()
{
    vector<int> arr = {1,2,3,3,3};

    cout << FirstOcc(arr,1,3) << endl;;
}