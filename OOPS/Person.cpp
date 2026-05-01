#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:

    string name;
    int age;

    public:

    Person(string n, int a)
    {
       name = n;
       age = a;
    }
};

class Student : public Person
{
    public:
    int StudId;

    Student(string n, int a, int i) : Person (n,a)
    {
       StudId = i;
    }

    void display()
    {
        cout << "Name = " << this-> name << endl;
        cout << "Age = " << this->age << endl;
        cout << "StudentID = " << this ->StudId << endl;
    }

};

int main()
{
    Student s1("fhgj", 123,55);
    s1.display();
    

}