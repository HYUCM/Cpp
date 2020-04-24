#include <iostream>

/*
Burada operation overloading diye bir teknik göstereceğim. Çok standart olan bir şey bu da.
Aslında overloadingin nasıl yapıldığını gördük senle. 
Copy&Move Constructor adlı klasöre git oradaki ClassZ.cpp dosyasına bak, orada ClassZ() adlı fonksiyonun (constructor'ın) aslında overloaded bir fonksiyon olduğunu göreceksin.
Overloadları birbirinden ayıran şey farklı parametre tipleri veya sayılarının olması.

Aynı işlemi temel operatörler için de yapabiliyoruz. Aritmetik, mantıksal, bitwise, [] gibi operatörler. Aşağıdaki class'ta buna birkaç örnek vermeye çalışacağım.
NOT : Buradaki rhs(right hand side) daha anlamlı olacak, çünkü bu operatörlerin sağ tarafından bahsediyor olacağız.
*/

class GoodClass {
public:
    int* list;
    int size;
    double data;

    GoodClass();
    GoodClass(int* _list, int _size, double data);
    ~GoodClass();

    

    bool operator==(GoodClass& rhs) const;
    bool operator<(GoodClass& rhs) const;
    bool operator>(GoodClass& rhs) const;

    // Copy assignment operator
    GoodClass& operator=(const GoodClass& rhs);

    // Move assignment operator
    GoodClass& operator=(GoodClass&& rhs);

    double operator+(GoodClass& rhs) const;
    double operator-(GoodClass& rhs) const;

    GoodClass& operator+=(const GoodClass& rhs);
    GoodClass& operator-=(const GoodClass& rhs);

    int operator[](int index) const;
  



};

GoodClass::GoodClass() {
    list = NULL;
    size = 0;
    data = 0;
}

GoodClass::GoodClass(int* _list, int _size, double _data) {
    data = _data;

    list = new int[size = _size];
    for (int i = 0; i < size; i++) {
        list[i] = _list[i];
    }
}


GoodClass::~GoodClass() {
    delete [] list;
}


// dataları eşitse doğru dönecek
bool GoodClass::operator==(GoodClass& rhs) const {
    if (rhs.data == data) {
        return true;
    }else {
        return false;
    }
}

// soldakinin datası sağdakinden küçükse doğru dönecek
bool GoodClass::operator<(GoodClass& rhs) const {
    if (data < rhs.data) {
        return true;
    }else {
        return false;
    }
}


// soldakinin datası sağdakinden büyükse doğru dönecek
bool GoodClass::operator>(GoodClass& rhs) const {
    if (data > rhs.data) {
        return true;
    }else {
        return false;
    }
}


// Copy Assignment : deep copy yapılacak, yani sağdaki değerlerin yenileri sıfırdan oluşturulacak
GoodClass& GoodClass::operator=(const GoodClass& rhs) {
    delete [] list;     // önce var olan list'i silelim, çünkü ihtiyacımız olmayacak

    size = rhs.size;
    list = new int[size];
    for (int i = 0; i < size; i++) {
        list[i] = rhs.list[i];
    }

    data = rhs.data;
}


// Move Assignment : shallow copy
GoodClass& GoodClass::operator=(GoodClass&& rhs) {
    delete [] list;
    
    list = std::move(rhs.list);
    size = std::move(rhs.size);
    data = std::move(rhs.data);

    rhs.list = NULL;
    rhs.size = 0;
    rhs.data = 0;

    // this diye bir pointer bir class'ın içinde her zaman bulunur, kendisine point eder.
    return *this;
}


double GoodClass::operator+(GoodClass& rhs) const {
    return data + rhs.data;
}

double GoodClass::operator-(GoodClass& rhs) const {
    return data - rhs.data;
}


GoodClass& GoodClass::operator+=(const GoodClass& rhs) {
    data += rhs.data;
    return *this;
}

GoodClass& GoodClass::operator-=(const GoodClass& rhs) {
    data -= rhs.data;
    return *this;
}


int GoodClass::operator[](int index) const {
    return this->list[index];
}