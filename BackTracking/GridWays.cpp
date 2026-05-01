#include <iostream>
#include <vector>
#include <string>
using namespace std;

int gridWays(int row, int col, int n, int m ,string ans)
{

    if( row == n - 1 && col == m - 1)
    {
        cout << ans << "\n";
        return 1;
    }

    if( row >= n || col >= m)
    {
        return 0;
    }

    int w1 = gridWays(row, col + 1, n, m, ans + 'R');
    int w2 = gridWays(row + 1, col, n, m, ans + 'D');
    int w3 = gridWays(row, col-1, n, m, ans+"L")
    

    return (w1 + w2);
}

int main()
{
    int n = 3, m = 3;
    string ans = "";
    cout << gridWays(0 , 0 , n , m, ans);

}