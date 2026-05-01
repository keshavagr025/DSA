#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //     vector<int> vec1 = {1, 2, 3, 4};

    //     cout << "Size :" << vec1.size() << endl;
    //     cout << "Capacity : " << vec1.capacity() << endl;

    //     vec1.push_back(0);
    //     cout << "Size :" << vec1.size() << endl;
    //     cout << "Capacity : " << vec1.capacity() << endl;

    //     vec1.pop_back(); // TO Delete the Last Element of my vector:

    //     cout << "Size :" << vec1.size() << endl;
    //     cout << "Capacity : " << vec1.capacity() << endl;

    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }

    cout << "Size :" << v.size() << endl;
    cout << "Capacity :"<< v.capacity() << endl;
}