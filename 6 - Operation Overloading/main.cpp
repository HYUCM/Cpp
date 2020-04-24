#include <iostream>
#include "GoodClass.h"

using namespace std;

int* generate_list(int x, int size) {
    int* temp = new int[size];
    for (int i = 0; i < size; i++) {
        temp[i] = i * x;
    }
    return temp;
}


int main() {
    GoodClass obj1;
    GoodClass obj2(generate_list(2, 10), 10, 3.3);
    GoodClass obj3(generate_list(5, 5), 5, 1.8);

    cout << "obj1 == obj2 -> " << (bool)(obj1 == obj2) << endl;
    cout << "obj1 < obj2 -> " << (bool)(obj1 < obj2) << endl;
    cout << "obj1 > obj2 -> " << (bool)(obj1 > obj2) << endl << endl;


    obj1 = obj2;
    cout << "Copy : obj1 = obj2 -> ";
    cout << "datas : " << obj1.data << ", " << obj2.data << " - ";
    cout << "sizes : " << obj1.size << ", " << obj2.size << " - ";
    cout << "lists :" << endl;
    for (int i = 0; i < obj1.size; i++) {
         cout << obj1.list[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < obj2.size; i++) {
        cout << obj2.list[i] << " ";
    }
    cout << endl << endl;


    obj1 = std::move(obj3);
    cout << "Move : obj1 = obj3 -> ";
    cout << "datas : " << obj1.data << ", " << obj3.data << " - ";
    cout << "sizes : " << obj1.size << ", " << obj3.size << " - ";
    cout << "lists :" << endl;
    for (int i = 0; i < obj1.size; i++) {
         cout << obj1.list[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < obj3.size; i++) {
        cout << obj3.list[i] << " ";
    }
    cout << endl << endl;


    cout << "obj1 + obj2 : " << (obj1 + obj2) << endl;
    cout << "obj1 - obj2 : " << (obj1 - obj2) << endl;

    obj1 += obj2;
    cout << "obj1 += obj2 : " << obj1.data << endl; 
    obj1 -= obj2;
    cout << "obj1 -= obj2 : " << obj1.data << endl << endl; 

    cout << "obj1[0] : " << obj1[0] << endl;
    cout << "obj1[1] : " << obj1[1] << endl;
    
    return 0;


}