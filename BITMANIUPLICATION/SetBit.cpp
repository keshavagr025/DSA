#include <iostream>
using namespace std;

int setBitMask(int num, int i){
    int bitMask = 1 << i;
    return (num | bitMask);
}

int main()
{
    cout << setBitMask(14,4) << endl;

}