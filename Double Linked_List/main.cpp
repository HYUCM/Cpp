#include <iostream>
#include "DLL.cpp"

// g++ .\main.cpp .\DLL.cpp -o test.exe
int main() {
    DLL ll1;

    ll1.insert(37, 0);
    ll1.insert(77, 1);
    ll1.insert(44, 2);
    ll1.insert(3, 3);
    ll1.insert(-8, 4);
    ll1.insert(7, 5);

    ll1.print_list();

    ll1.insert(8, 3);
    ll1.print_list();

    return 0;

}