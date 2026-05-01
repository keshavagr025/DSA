#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[v].push_back(u);
        l[u].push_back(v);
    }

    void print()
    {

        for (int u = 0; u < V; u++)
        {
            list<int> neigbhours = l[u];
            cout << u << ":";
            for (int V : neigbhours)
            {
                cout << V << " ";
            }
            cout << endl;
        }
    }

    bool BSF(int src, int dest)
    {
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0); // src node or src ppointer

        vis[src] = true;

        while (q.size() > 0)
        {
            if(src == dest){
                return true;
            }

            int u = q.front();
            q.pop();

            list<int> neighbours = l[u];
            for (int v : neighbours)
            {
                if (!vis[v])
                {
                   if(BSF(v, dest)){
                    return true;
                   }
                }
            }
        }

        return false;
    }

};

int main()
{
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    cout << graph.BSF(0,5);
}