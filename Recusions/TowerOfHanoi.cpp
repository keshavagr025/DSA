#include <iostream>
using namespace std;
 
void TowerOfHanoi(int n, string src, string helper, string des)
{
    // Base case: 
    if (n == 1)
    {
        cout << "Transfer disk " << n << " from " << src << " to " << des << endl;
        return; 
    }

    // Transfer top n-1 disks from source to helper using destination as 'helper'
    TowerOfHanoi(n - 1, src, des, helper);

    // Transfer nth disk from source to destination
    cout << "Transfer disk " << n << " from " << src << " to " << des << endl;

    // Transfer n-1 disks from helper to destination using source as 'helper'
    TowerOfHanoi(n - 1, helper, src, des);
} bv          

int main()
{
    int n = 3;
    TowerOfHanoi(3, "A", "B", "C");
    return 0;
}
