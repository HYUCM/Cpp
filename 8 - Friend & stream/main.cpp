#include "DArray.cpp"

using namespace std;

// g++ main.cpp -o Test.out
int main() {
    DArray x, y;
    x.insert(5);
    x.insert(6);
    x.insert(7);
    x.insert(8);
    x.insert(9);
    x.insert(10);

    y.insert(-5);
    y.insert(-6);
    y.insert(-7);
    y.insert(-8);
    y.insert(-9);
    y.insert(-10);

    cout << x << endl << endl;
    cout << y << endl;

    return 0;
}