#include <iostream>
#include <lmerr.h>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<pair<int, int>> * l;

public:
    
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int >> [V];
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v,wt));
        l[v].push_back(make_pair(u, wt));
    }

       void print() {
        for (int u = 0; u < V; u++) {
            list<pair<int, int>> neighbors = l[u];
            cout << u << ": ";
            for (auto neighbor : neighbors) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph graph(5);

    
    graph.addEdge(0,1,5);
    graph.addEdge(1,2,1);
    graph.addEdge(1,3,3);
    graph.addEdge(2,3,1);
    graph.addEdge(2,4,2);
    graph.addEdge(2,1,1);
    graph.addEdge(4,2,2);

    graph.print();
}