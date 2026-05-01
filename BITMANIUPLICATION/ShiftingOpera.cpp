#include <iostream>
using namespace std;

int main()
{

  cout << (2 << 3) << endl; // a * 2^b = 2 * 2^3 = 2*8 = 16
  cout << (2 >> 3) << endl; // a/2^b   = 2/2^3 = 0

  return 0;
}