#include <iostream>
#include <vector>
#include <queue>
#include <list>

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

    void dfsHelper(int u, vector<bool> &vis){
        cout << u << " ";
        vis[u] = true;
        list<int> neighbours = l[u];
        for(int v : neighbours){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        } 
    }

    void dfs(){
        vector<bool> vis(7, false);

        dfsHelper(0, vis);
    }
    
};

int main()
{
    Graph graph(7);

    graph.edgeAdd(0, 1);
    graph.edgeAdd(0, 2);
    graph.edgeAdd(1, 3);
    graph.edgeAdd(2, 4);
    graph.edgeAdd(3, 4);
    graph.edgeAdd(3, 5);
    graph.edgeAdd(4, 5);
    graph.edgeAdd(5, 6);


    graph.dfs();

    return 0;
}