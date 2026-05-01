#include <iostream>
#include <cstring>
using namespace std;

void Vowel(char word[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        
     if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            cnt++;
        }
    }
    
    cout << "Count of vowels is = " << cnt << endl;
}

void Swapp(char s[], char t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(s, t);
    }
    
    cout << s  << endl;
}

int main()
{
    char t[] = "apple";
    char s[] = "";

    // Vowel(word, strlen(word));

    Swapp(t,s,strlen(t));

}