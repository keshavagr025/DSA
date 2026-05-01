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
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i, vis);
            cout << endl;
            }
        }
    }

    // BFS

     void BSFhelper(int str,  vector<bool> &vis)
    {
        queue<int> q;
        q.push(str); // src node or src ppointer
        vis[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            list<int> neighbours = l[u];
            for (int v : neighbours)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

    }

    void bfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                BSFhelper(i, vis);
                cout << endl;
            }
        }
    }
    
};

int main()
{
    Graph graph(10);

    graph.edgeAdd(0, 2);
    graph.edgeAdd(2, 5);
    graph.edgeAdd(1, 6);
    graph.edgeAdd(6, 4);
    graph.edgeAdd(4, 6);
    graph.edgeAdd(4, 3);
    graph.edgeAdd(3, 7);
    graph.edgeAdd(3, 8);
    graph.edgeAdd(4, 9);

    // graph.dfs();
    graph.bfs();

    return 0;
}