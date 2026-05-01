#include<iostream>
using namespace std;

bool Twice(int *nums,int n)
{
    int cnt = 0;
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i] == nums[j])
            {
                cout << nums[j] << endl;
            }else
            {
                return 0;
            }
        }
    }

   
    

}

int main()
{
    int nums[] = {1,2,3,4,5};
    int n = sizeof(nums)/sizeof(int);

    cout << Twice(nums, n) << endl;

}