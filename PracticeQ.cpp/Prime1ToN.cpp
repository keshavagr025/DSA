#include<iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter numnber = " << endl;
   cin >> n;

   for (int i = 2; i <= n; i++)
   {
     int curr = i;

     bool isPrime = true;

     for(int j=2; j*j<=i; j++)
     {
        if(curr % j == 0)
        isPrime = false;
     }
   
   if(isPrime)
   {
    cout << curr << endl;
   }

   }


   
}