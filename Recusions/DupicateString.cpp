#include <iostream>
#include <string>
using namespace std;
 
// void Dupicate(string str, string  ans, int i, int map[26])
// {
//     if( i == str.size())
//     {
//         cout << "Ans :" << ans << endl;
//         return;
//     }

//     int mapIdx = (int)(str[i] -'a');

//     if(map[mapIdx]){
//         Dupicate(str, ans, i+1, map);
//     }else{
//         map[mapIdx] = true;
//         Dupicate(str, ans + str[i], i+1, map);
//     }
// }

// Reverse wroking function 

void Dupicate(string str, string  ans, int map[26])
{
    if(str.size() == 0)
    {
        cout << "Ans :" << ans << endl;
        return;
    }

    int n = str.size();
    char ch = str[n-1];

    int mapIdx = (int)(str[n-1] -'a');
    str = str.substr( 0,n-1);

    if(map[mapIdx]){
        Dupicate(str, ans,  map);
    }else{
        map[mapIdx] = true;
        Dupicate(str, ch + ans,  map);
    }
}
int main()
{
    string str = "aapnnacoollegee";
    string ans = " ";

    int map[26] = {false};

    Dupicate(str , ans , map);
}