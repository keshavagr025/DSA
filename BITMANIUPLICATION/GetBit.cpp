#include<iostream>
using namespace std;
 
int getIthBit(int num, int i)
{
    // left most << operator
    // 1 << i creates a bitmask with the ith bit set to 1

    // For example number = 6 (binary 110)
    // and i = 2, then bitMask = 1 << 2 = 4 (binary 100)
    // The bitwise AND & operator checks if the ith bit in num is set to 1 or not.
    // If it is set, it returns 1, otherwise it returns 0.  

    int bitMask = 1 << i;
    
    if(!(num & bitMask)){
      return 0;
    }else{
      return 1;
    }
}
int main()
{
  cout << getIthBit(7,2) << endl;
 
  return 0;
}