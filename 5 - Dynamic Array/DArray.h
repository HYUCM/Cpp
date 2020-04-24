#include <iostream>

/*
Burada göstermeye çalıştığım şey dinamik şekilde büyümesi gerekebilecek bir arrayin nasıl kontrol edildiği
Buna "Dynamic memory management" deniyor. Daha önceden de bahsetmiştim de, bi de c++ class'ı olarak anlatayım dedim.
Data dersinde kullanacağın bazı yapılarda bu mantık kullanılacak. (Hash Table, Stack, Queue, Heap gibi)
Hatta std::vector classına da bak, benim burada anlattığım şeyler onun temeli.

NOT : main yazmıyorum bu class'a üşendim çünkü :D, istersen sen kendin yazarsın, nasıl yapacağını biliyorsun.
*/

class DArray {
private:
    int* darray;
    int size;
    int capacity;
public:
    DArray();
    ~DArray();

    int find(int data) const;

    void insert(int data);

    void remove();

    void resize();

    void print() const;
    
};

DArray::DArray() {
    darray = NULL;
    size = 0;
    capacity = 0;
}

DArray::~DArray() {
    delete [] darray;
}


// eğer data, array'de varsa indexini dön, yoksa -1 dön
int DArray::find(int data) const {
    for (int i = 0; i < size; i++) {
        if (darray[i] == data) {
            return i;
        }
    }
    return -1;
}

// sona ekler
void DArray::insert(int data) {
    if (size == capacity) {
        resize();
    }

    darray[size] = data;
    size++;
}


// sondan siler
// veriyi cidden silmesine gerek yok, çünkü istediğimiz gibi üstüne yazabiliriz o var olan verinin üzerine
// zaten arrayimizin kullandığımız kısmı 0-size arasındaki indexler
void DArray::remove() {
    size--;
}


// kapasiteyi iki katına çıkar
void DArray::resize() {
    int _capacity;
    if (capacity == 0) {
        _capacity = 5;
    }else {
        _capacity = 2 * capacity;;
    }


    int* temp = new int[_capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = darray[i];
    }

    delete [] darray;
    darray = temp;

    capacity = _capacity;
}

void DArray::print() const {
    if (size == 0) {
        std::cout << "Empty Array!" << std::endl;
    }else {
        for (int i = 0; i < size-1; i++) {
            std::cout << darray[i] << " - ";
        }
        std::cout << darray[size-1] << std::endl;    
    }
}



