#include<iostream>
#include<cstring>
using namespace std;

// o(n/2);
void Reverse(char word[], int n)
{
    int str = 0;  int end = n-1;
    while (str < end){  swap(word[str++], word[end--]); }
}

int main()
{
    char word[] = "Keshav is a good boy";
    Reverse(word, strlen(word));
    cout << word ;

}