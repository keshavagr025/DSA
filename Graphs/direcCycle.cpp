#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isUndirc;

public:
    
    Graph(int V, bool isUndirc){ // by default its true:
        this->V = V;
        l = new list<int>[V];
        this->isUndirc = isUndirc; 
    }

    void addEdge(int u, int v){  // u--->v
        l[u].push_back(v);
        if(isUndirc) // undirected ke liye false value rahti h...
            l[v].push_back(u);
    }


    bool direCyclehelper(int src, vector<bool> &vis, vector<bool> &recrPath){
        vis[src] = true;
        recrPath[src] = true;

        list<int> neighbours = l[src];

        for(int v : neighbours){
            if(!vis[v]){
                if(direCyclehelper(v, vis, recrPath)){
                    return true;
                }
            }else{
                if(recrPath[v]){
                    return true;
                }
            }
        }

        recrPath[src] = false;
        return false;
    }

    bool direCycle(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(direCyclehelper(i, vis, recPath)){  // for components of graphs
                    return true;
                }
            }
        }

        return false;
    }

};

int main(){

    Graph graph(4, false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    // graph.addEdge(3,0);

    if(graph.direCycle() == true){
        cout << "Cycle is present = " << graph.direCycle() << endl;
    }else{
        cout << "Cycle is not present = " << graph.direCycle() << endl;
    }
    return 0;
}