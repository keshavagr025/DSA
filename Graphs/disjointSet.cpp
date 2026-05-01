#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class disjointSet
{
public:
    int n;
    vector<int> par;
    vector<int> rank;

    disjointSet(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }

        return find(par[x]);
    }

    void unionbyFind(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (rank[parA] == rank[parB])
        {
           par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }
        else
        {
            par[parA] = parB;
        }
    }

    void getInfo()
    {

        for (int i = 0; i < n; i++)
        {
            cout << i << ":" << par[i] << "," << rank[i] << endl;
        }
    }
};

int main()
{
    disjointSet dj(6);
    dj.unionbyFind(0, 2);
    cout << dj.find(2) << endl;
    dj.unionbyFind(1, 3);
    dj.unionbyFind(2, 5);
    dj.unionbyFind(0, 3);
    cout << dj.find(2) << endl;
    dj.unionbyFind(0, 4);

    dj.getInfo();
}