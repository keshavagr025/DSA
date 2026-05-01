#include <iostream>
using namespace std;

//  2 + 2i  - 4 + 3i = (-2 - i)

class ComplexNumber{
    private:
    float rel;
    float img;

    public:

    void operator sub-(float x, int float y){
        rel = rel.x - img.x;
        img = rel.y - img.y;

        cout << rel << "," << img << endl;
    }
};

int main(){
    ComplexNumber c1;
    c1.sub()
}