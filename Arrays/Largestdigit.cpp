#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <hashtable.h>
#include <hash_map>
#include <map>
using namespace std;

static bool compare(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);

    if(s1+s2 > s2+s1){
        return true;
    }

    return false;
}


void largestNumber(string nums)
{
    sort(nums.begin(), nums.end(), compare);

    if(nums[0] == 0){
        return "0";
    }

    string str = "";
    for(auto& it : nums){
        str += to_string(it;)
    }

    return str;
}


int main()
{
    string

}
