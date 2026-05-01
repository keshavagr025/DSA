#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph{
    int V;
    list<pair<int, int>> * l;
    bool isUndire;

public:
    
    Graph(int V, bool isUndire = true){
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->isUndire = isUndire;
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v, wt));
        if(isUndire)
            l[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src){

        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        // (wt, u) --> min heap

        vector<bool> Mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0;

        while(pq.size() > 0){
            int u = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            if(!Mst[u]){
                Mst[u] = true;
                ans += wt;

                list<pair<int, int>> negh = l[u];
                for(pair<int, int> n : negh){
                    int v = n.first;
                    int currWt = n.second;

                    pq.push(make_pair(currWt, v));
                }
            }
        }

        cout << "The cost of the Mst = " << ans << endl;
    }

};

int main(){
    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);

    graph.addEdge(1,3,40);

    graph.addEdge(2,3,50);

    
   graph.primsAlgo(0);
   return 0;

}