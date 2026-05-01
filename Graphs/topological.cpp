#include <iostream>
#include <stack>
#include <vector>
#include <assert.h>
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

    void topoHelper(int src, vector<bool>& vis, stack<int>& st){
        vis[src] = true;
        list<int> negh = l[src];
        for(int v : negh){
            if(!vis[v]){
                topoHelper(v, vis, st);
            }
        }

        st.push(src);
    }

    void topological(){
        vector<bool> vis(V, false);
        stack<int>st;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoHelper(i, vis, st);
            }
        }

        while(st.size() > 0){
            cout << st.top() << " ";
            st.pop();
        }
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

    graph.topological();

    return 0;
}