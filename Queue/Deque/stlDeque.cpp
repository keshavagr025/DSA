#include <iostream>
#include <queue>

using namespace std;

int main()
{
    deque<int> deq;

    deq.push_back(2);
    deq.push_back(1);

    deq.push_front(3);
    deq.push_front(4);

    deq.pop_front();
    deq.pop_back();
    deq.front();
    deq.back();
}