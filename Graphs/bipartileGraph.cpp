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

    bool isBipartile()
    {
        queue<int> q;
        // vector<bool> vis(V, false);
        vector<int> color(V, -1);

        // vis[0] = 0;
        q.push(0);
        color[0] = 0;

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            list<int> neighbours = l[curr];

            for (int v : neighbours)
            {
                if (color[v] == -1)
                {
                    // vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }
                else
                {
                    if (color[v] == color[curr])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{ 
    // unDirected bipartile Graph
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(0, 3);


    // graph.addEdge(3, 5);
    // graph.addEdge(4, 5);
    // graph.addEdge(5, 6);

    cout << graph.isBipartile() << endl;
}