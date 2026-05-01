#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void StockSpan(vector<int> stock, vector<int> span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < stock.size(); i++)
    {
        int currPrice = stock[i];
        while (!s.empty() && currPrice >= stock[s.top()])
        {
            s.pop();
        }
        // special case
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
    }

    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
S
    cout << endl;
}

// using array 
// void calculateSpan(int price[], int n)
//     {
//         vector<int> span(n);
//         stack<int>s;
//         s.push(0);
//         span[0] = 1;
        
//         for(int i=1; i<n; i++){
//             int currPrice = price[i];
//               while(!s.empty() && currPrice >= price[s.top()]){
//                   s.pop();
//               }
              
//               if(s.empty()){ // special case
//                  span[i] = i + 1;
//               }else{
//                   int prevHigh = s.top();
//                   span[i] = i - prevHigh;
//               }
              
//               s.push(i);
//         }
       
//        return span;
//     }

int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    StockSpan(stock, span);
}