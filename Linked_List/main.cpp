#include <iostream>
#include "Linked_List.cpp"

// g++ .\main.cpp .\Linked_List.cpp -o test.exe
int main() {
    Linked_List ll1;

    ll1.insert(0);
    ll1.insert(1);
    ll1.insert(2);
    ll1.insert(3);
    ll1.insert(4);
    ll1.insert(5);

    ll1.print_list();

    return 0;

}