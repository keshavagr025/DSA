// O(N+M)

#include <iostream>
#include <string>
using namespace std;

int fact(int n, int m)
{
    int fat = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fat = fat*(i+j) / fat*i * fat*j;
        }
    }

    cout << fat << endl;
}

// int GridWays(int row, int col, int n, int m)
// {
//     if( row == n-1 && col == m-1)
//     {
//         return 1;
//     }

//     if( row == n || col == m)
//     {
//         return 0;
//     }
// }

int main()
{
    int n = 3, m = 3;

    cout << fact(n, m);
}