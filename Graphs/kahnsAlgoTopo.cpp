#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool undir;
public:
    Graph(int V, bool undir){
        this->V = V;
        l = new list<int> [V];
        this->undir = undir; 
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(undir)
            l[v].push_back(u);
    }


    void calcIndegree(vector<int>& indeg){
        for(int i=0; i<V; i++){
            list<int> neig = l[i];
            for(int v : neig){
                indeg[v]++;
            }
        }
    }
    void topoSort2(){
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;

        // 0 indeg nodes starting point
        for(int i=0; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){
            int curr = q.front();
            q.pop();

            cout << curr << " ";
            list<int> negh = l[curr];

            for(int v : negh){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();

    return 0;
}