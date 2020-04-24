#include <iostream>

/*
C++'ta stream'ler vardır. Bu streamler bir yerden başka bir yere bilgi akışını sağlarlar. Mesela senin programından terminale(standart output'a), bu mesela cout olur.
Veya standart input'tan senin programına (cin). Mesela bir dosyadan programına bilgi çekmek için fstream diye bir stream kullanırsın.
Bilginin akış yönünü göstermek için << veya >> kullanırız. Bunlar kendileri birer operatördür.
Bu streamlerin hepsi iostream'le include'luyorsun.
Neden stream kullanmalısın? Çünkü, işini aşırı kolaylaştırıyor bilgiyi aktarırken. Mesela aşağıdaki class'ta darray'in indexlerini teker teker bastırmak için
ayrı bir for döngüsü falan yazman gerekecek. Bunun yerine, o indexleri ayrı bir fonksiyonda, teker teker, senin istediğin formatta "ostream"e verirsin (output stream), daha
sonra ostream'i cout'a verirsin. Bunun için bir fonksiyon tanımlamış olacağından da direkt "cout << obj_x << endl" kullanarak bir objeyi bastırabilirsin mesela.

Ek bir bilgi daha : class'ların içinde friend class'lar ve fonksiyonlar tanımlayabiliyorsun. Mesela ClassA'nın tanımına "friend ClassB" satırını koyarsan, ClassB, ClassA'nın
private değişkenlerine, fonksiyonlarına ulaşabilir. Aynı şeyi fonksiyonlar için de yapabilirsin : Bir fonksiyon class'ın friend'i ise, o class'ın tüm bilgilerine ulaşabilir.
*/

class DArray {
private:
    int* darray;
    int size;
    int capacity;
public:
    DArray();
    ~DArray();

    // data varsa indexini döner, yoksa -1 döner
    int find(int data) const;

    // sona ekler
    void insert(int data);

    // sondan siler
    void remove();

    // kapasiteyi 2 katına çıkarır
    void resize();

    // Bir önceki konuda "stream overload" diye bir şeyden bahsetmiştim. Aha bu arkadaş işte. << ve >> aslında birer operatör c++'ta.
    // Normalde, standart tipleri (int,char...) kabul ediyor, ama sen overload yaparak başka tipleri de kabul etmesini sağlayabiliyorsun.
    // Bu fonksiyonun tanımı en sonda.
    // NOT : Class fonksiyonu değil bu, sebebi azıcık karmaşık bir şeydi, ben anlamamıştım :D   
    friend std::ostream& operator<<(std::ostream& os, const DArray& transaction);

    
};

DArray::DArray() {
    darray = NULL;
    size = 0;
    capacity = 0;
}

DArray::~DArray() {
    delete [] darray;
}

int DArray::find(int data) const {
    for (int i = 0; i < size; i++) {
        if (darray[i] == data) {
            return i;
        }
    }
    return -1;
}

void DArray::insert(int data) {
    if (size == capacity) {
        resize();
    }

    darray[size] = data;
    size++;
}

void DArray::remove() {
    size--;
}

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


std::ostream& operator<<(std::ostream& os, const DArray& rhs) {
    os << "Size : " << rhs.size << std::endl;
    os << "Capacity : " << rhs.capacity << std::endl;
    
    if (rhs.size == 0) {
        os << "EMPTY ARRAY" << std::endl; 
    }else if (rhs.size == 1) {
        os << rhs.darray[0] << std::endl;
    }else {
        for (int i = 0; i < rhs.size - 1; i++) {
            os << rhs.darray[i] << " - ";
        }
        os << rhs.darray[rhs.size-1];
    }

    return os;
}

// https://medium.com/@nonuruzun/overloading-input-output-operators-in-c-a2a74c5dda8a
// ostream'i anlayınca bi de bu linke bak. Burada hem ostream hem istream'e örnekler vermiş.