#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm> // Include this header for std::sort

using namespace std;

class Edge {
public:
   int u;
   int v;
   int wt;

   Edge(int u, int v, int wt){
    this->u = u;
    this->v = v;
    this->wt = wt;
   }
};

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V){
        this->V = V;
        par.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++) {
            par[i] = i;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b){
        int parU = find(a);
        int parV = find(b);

        if(rank[parU] == rank[parV]){
            par[parV] = parU;
            rank[parU]++;
        }else if(rank[parU] > rank[parV]){
            par[parV] = parU;
        }else{
            par[parU] = parV;
        }
    }

    void kruskalAlgo(){
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) { return a.wt < b.wt; });

        int minCost = 0;
        int count = 0;

        for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            if (parU != parV) {
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }
        cout << "Min cost is = " << minCost << endl;
        cout << "The count will be = " << count << endl;
    }
};

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.kruskalAlgo();
}
