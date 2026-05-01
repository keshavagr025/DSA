#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string>

using namespace std;

class Graph{ 
    int V;
    list<int> * l;

public:
    
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void edgeAdd(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        
        for(int u = 0; u < V; u++){
            cout << u << " ";
            list<int> neighbours = l[u];
            for(int v :  neighbours){
                cout << v << ":";
            }
            cout << endl;
        }
    }

    bool undirCycleHelper(int src, int par, vector<bool> & vis){ // O(V + E)
        vis[src] = true;
        list<int> negh = l[src];

        for(int v : negh){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
              
            }else{
                if(v != par){ // cycle detection
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }
    
};

int main()
{
    Graph graph(5);

    // undirected Graph
    graph.edgeAdd(0, 1);
    // graph.edgeAdd(0, 2);
    graph.edgeAdd(0, 3);
    graph.edgeAdd(1, 2);
    graph.edgeAdd(3, 4);

    cout << graph.isCycleUndir();


    return 0;
}