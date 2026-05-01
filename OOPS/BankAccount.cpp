#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accNumber;
    int balance;

public:
    
    void Details()
    {
        cout << "Enter Your Account Number = "<< " ";
        cin >> accNumber;
        cout << "Enter Your Balance = " << " ";
        cin >> balance;
    }
    void deposit(int depo)
    {
        balance += depo;
        cout << "Balance is Added is Your Account = " << depo << endl;
    }
    void withdraw(int withAm)
    {
        if (withAm <= balance)
        {
            balance -= withAm;
        }else
        {
            cout << "Insufficient money" << endl;
        }
    }
    void Show()
    {
        cout << "Your Account Number is = " << accNumber << endl;
        cout << "Your Balance is = " << balance << endl;
    }
    void getBalance()
    {
        cout << "Reamaning Balance is = " << balance << endl;
    }
};

int main()
{
    BankAccount b1;
    b1.Details();
    b1.deposit(50000);
    b1.withdraw(10000);
    b1.getBalance();
    return 0;
}