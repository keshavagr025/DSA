#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<double, int> p1, pair<double, int> p2){

    return p1.first > p2.first; 
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){

    int n = val.size();
    vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); // pair(ratio, idx) --> (double, int)

    for(int i=0; i<n; i++){
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    int ans = 0;

    for(int i=0; i<n; i++){
        int idx = ratio[i].second; // gives index of wt, val

        if(wt[idx] <= w){
            ans += val[idx];
            w -= wt[idx];
        }else{
            ans += ratio[i].first * w; 
            break;
        }
    }

    cout << "max value " << ans << endl;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    fractionalKnapsack(val, wt, 50);
}