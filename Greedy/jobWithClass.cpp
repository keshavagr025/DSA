#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class job{
    public:

    int idx;
    int deadLine;
    int profit;

    job(int idx, int deadLine, int profit){
        this->idx = idx;
        this->deadLine = deadLine;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs){
    int n = pairs.size();

    vector<job> jobs;

    for(int i=0; i<n; i++){
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](job &a , job &b){  // [] -- capture list , () this is lambda function
        return a.profit > b.profit; // decending order sort
    });

      cout << "selecting a job " << jobs[0].idx << endl;

    int safeDeadLine = 2;
    int profit = jobs[0].profit;
    for(int i=0; i<n; i++){
        if(jobs[i].deadLine >= safeDeadLine){
            cout << "selecting a job" << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadLine++;

        }
    }

    cout << "Max Profit id = " << profit << endl;
}

int main(){
    int n = 4;

    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);
}