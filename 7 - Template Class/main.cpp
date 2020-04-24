#include "ClassA.cpp"
#include <iostream>

using namespace std;

// g++ main.cpp -o Test.out
// konuyla alakasız : #include'ların sırasına dikkat et, böyle de oluyormuş :D
int main() {
    int *pi;
    char *pc;
    float *pf;

    int size_i = 5, size_c = 7, size_f = 9;
    pi = new int[size_i];
    pc = new char[size_c];
    pf = new float[size_f];

    for (int i = 0; i < size_i; i++) {
        pi[i] = i + 3;
    }
    for (int i = 0; i < size_c; i++) {
        pc[i] = i + 70;
    }
    for (int i = 0; i < size_f; i++) {
        pf[i] = i + 3.8;
    }


    ClassA<int> obj_int(pi, size_i);
    ClassA<char> obj_char(pc, size_c);
    ClassA<float> obj_float(pf, size_f);

    cout << "obj_int:" << endl;
    obj_int.print();
    cout << "obj_char" << endl;
    obj_char.print();
    cout << "obj_float" << endl;
    obj_float.print();

    int *ehe = obj_int.get_array();
    for (int i = 0; i < size_i; i++) {
        cout << ehe[i] << " ";
    }
    cout << endl;


    myClass obj1, obj2;
    obj1.a = 1, obj1.b = 2;
    obj2.a = 3, obj2.b = 4;

    myClass *temp = new myClass[2];
    temp[0] = obj1;
    temp[1] = obj2;

    ClassA<myClass> obj_class(temp, 2);
    cout << "T bir class olursa:" << endl; 
    cout << obj_class.array[0].a << "," << obj_class.array[0].b << endl;
    cout << obj_class.array[1].a << "," << obj_class.array[1].b << endl;
    // burada manuel olarak bastırıyorum çünkü myClass classının "stream overload" operatörü tanımlı değil henüz.
    // yani bunun türkçesi, cout'a direkt myClass objesini veremeyiz.
    // onun yöntemi de var, daha sonra o ;)

    return 0;
}