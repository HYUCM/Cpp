#include "ClassA.h"
#include <iostream>

/*
Class fonksiyonlarını class dışında tanımlamak isteyeceksin gene. Bunu template class'ta yapmak gene gayet kolay:
İlk olarak template <class A1,......,class An> satırını başa koyuyorsun. Sonra da şu şekilde bir satır getiriyorsun:
return_type Classİsmi<Şablon değişkenler>::Fonksiyonİsmi(parametreler) {}

NOT : Şablon değişkenler başka classlar a olabilir ;) işin güzel kısmı burada.
NOT : Teknik olarak int float falan filan da c++'ta birer class. 
*/

template <class T>
ClassA<T>::ClassA() {
    array = NULL;
    size = 0;
}

template <class T>
ClassA<T>::ClassA(T *_array, int _size) {
    size = _size;
    array = new T[size];

    for (int i = 0; i < size; i++) {
        array[i] = _array[i];
    }
}

template <class T>
ClassA<T>::~ClassA() {
    delete [] array;
}

template <class T>
void ClassA<T>::print() {
    std::cout << "Size : " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
T* ClassA<T>::get_array() {
    if (array == NULL) {
        return NULL;
    }

    T* temp = new T[size];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    return temp;
}

//-------------------------------------------------------------------------------------
//-------------BAŞKA BİR CLASS, KONUYLA ALAKASIZ, ÖRNEK İÇİN KULLANACAĞIZ--------------
//-------------------------------------------------------------------------------------
class myClass {
public:
    int a;
    int b;

    myClass();
    ~myClass();

    int sum() const;

};

myClass::myClass() {
    a = b = 0;
}


myClass::~myClass() {}


int myClass::sum() const {
    return a + b;
}
