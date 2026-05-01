#include <iostream>
#include<cmath>
using namespace std;

void MaxProfit(int *prices, int n)
{
    int bestBuy[100000];
    bestBuy[0] = INT16_MAX;

    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        cout << bestBuy[i] << ",";
    }

    int MaxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int CurrProfit = prices[i] - bestBuy[i];  // sell - buy;
        MaxProfit = max(MaxProfit,CurrProfit);
    }

    cout << "Maximum Profit = " << MaxProfit << endl;
}

int main()
{
    int prices[6] = {7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(int);

    MaxProfit(prices,n);

}