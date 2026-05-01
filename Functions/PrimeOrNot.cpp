#include<iostream>
using namespace std;

void CheckPrime(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            cout << "not Prime" << endl;
            break;
        }else
        {
            cout << " Prime" << endl;
            break;
        }
    }
}

bool isPrime(int n)
{
    if(n == 1)
    {
        return 1;
    }

    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    
     isPrime(10);

   
}