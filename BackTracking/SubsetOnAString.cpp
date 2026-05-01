// #include <iostream>
// #include<string>
// using namespace std;
 
// void Substring(string str, string sbstr)
// {
//     if(str.size() == 0)
//     {
//         cout << sbstr ;
//         return;
//     }

//     int n = str.size();
//     char ch = str[0];

//     Substring(str.substr(1,n-1), sbstr + ch); // yes :

//     Substring(str.substr(1, n-1), sbstr); // No :
// }
// int main()
// {
//     string str = "abc";
//     string sbstr = " ";

//     Substring(str,sbstr);  
// }




#include <iostream>
#include<string>
#include <vector>
using namespace std;

void printArr(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
}
void Subset(vector<int>str, vector<int> sbstr)
{
    if(str.size() == 0)
    {
       printArr(sbstr);
        return;
    }

    int ch = str[0];
    str.erase(str.begin());

    vector<int> sbstrWithCh = sbstr;
    sbstrWithCh.push_back(ch);

    Subset(str, sbstrWithCh ); // yes :
    Subset(str, sbstr); // No :
}
int main()
{
    vector<int>str ={1,2,3};
    vector<int>sbstr;

    Subset(str,sbstr);  
}