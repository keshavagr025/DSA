#include <iostream>
using namespace std;

bool SearchSorted(int matrix[][4], int m, int key)
{
    int i = 0, j = m - 1;
    //   T.c = O(n+m)
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == key)
        {
            cout << "(" << i << "," << j << ")\n";
            return true;
        }
        else if (matrix[i][j] > key)
        {
            // left
            j--;
        }
        else
        {
            // down
            i++;
        }
    }

    cout << "Key Not Found" << endl;
}

int main()
{
    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};

    SearchSorted(matrix, 4, 33);
}