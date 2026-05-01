// An elephant decided to visit his friend. It turned out that the elephant's house is located at point 0 and his friend's
// house is located at point x(x > 0) of the coordinate line. In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. 
// Determine, what is the minimum number of steps he need to make in order to get to his friend's house.

#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    int steps = 0;
    while (x > 0) {
        x -= 5; // The elephant can move up to 5 positions in one step
        steps++;
    }
    cout << steps << endl; // Output the total number of steps taken
    return 0;
}
