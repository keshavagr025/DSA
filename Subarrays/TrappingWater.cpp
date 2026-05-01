#include <iostream>
using namespace std;

int TrapWater(int *heigth, int n)
{
    int leftMax[20000] , RightMax[20000];
    leftMax[0] = heigth[0];

    RightMax[n - 1] = heigth[n - 1];

    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], heigth[i - 1]);
        // cout << leftMax[i] << ",";
    }
    cout << endl;

    for (int i = n - 2; i >= 0; i--)
    {
        RightMax[i] = max(RightMax[i + 1], heigth[i + 1]);
        // cout << RightMax[i] << ",";
    }

    int Trapwater = 0;
    for (int i = 1; i <n; i++)
    {
        int CurrWater = min(leftMax[i], RightMax[i]) - heigth[i];
        if (CurrWater > 0)
        {
            Trapwater += CurrWater;
        }
    }

    cout << "TrapWater = " << Trapwater << endl;
}

int main()
{
    int heigth[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(heigth) / sizeof(int);

    TrapWater(heigth, n);
}