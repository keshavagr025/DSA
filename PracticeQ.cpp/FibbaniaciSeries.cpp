#include<iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter a number n" << endl;
    cin >> n;

   int first = 0;
   int third;
   int sec =  1;
   
   cout << first << " " << sec << " ";

   for(int i = 2; i<=n; i++)
   {
    third = first + sec;
    first = sec;
    sec = third;
   }

    cout << third << " ";

}