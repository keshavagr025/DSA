#include <iostream>
using namespace std;

// Function to get the next alphabet character
char nextAlphabate(char a)
{
    if (a >= 'a' && a < 'z') {
        return a + 1; // Next character in lowercase
    } else if (a >= 'A' && a < 'Z') {
        return a + 1; // Next character in uppercase
    } else if (a == 'z') {
        return 'a'; // Wrap around for 'z'
    } else if (a == 'Z') {
        return 'A'; // Wrap around for 'Z'
    } else {
        return a; // Return the same character if it's not a letter
    }
}

int main()
{
    char c, y;
    cout << "Enter the character: ";
    cin >> c;

    do {
        char nextChar = nextAlphabate(c);
        cout << "Next character: " << nextChar << endl;

        cout << "Do you want to continue? (y = yes, any other key = no): ";
        cin >> y;

        if (y == 'y' || y == 'Y') {
            c = nextChar; // Update to the next character
        } else {
            cout << "Goodbye!" << endl;
            break;
        }
    } while (true);

    return 0;
}
