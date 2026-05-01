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

    void BSF()
    {
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0); // src node or src ppointer

        vis[0] = true;
        int cnt = 0;

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
                    cnt++;
                }
            }
        }

        cout << "Answer = " << cnt << endl;

        cout << endl;
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

    graph.BSF();
}


