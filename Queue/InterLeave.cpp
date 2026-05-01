#include <iostream>
#include <queue>

using namespace std;

void interLeaves(queue<int> &org)
{
    int n = org.size();
    queue<int> frist;

    for(int i=0; i<n/2; i++){
        frist.push(org.front());
        org.pop();
    }

    while(!frist.empty()){
        org.push(frist.front());
        frist.pop();

        org.push(org.front());
        org.pop();
    }
}
int main()
{
    queue<int> org;

    for(int i=1; i<=10; i++){
        org.push(i);
    }

    interLeaves(org);

    for(int i=1; i<=10; i++){
        cout << org.front() << " ";
        org.pop();
    }

    cout << endl;

    return 0;
}