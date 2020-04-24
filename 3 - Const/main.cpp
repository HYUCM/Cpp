#include <iostream>

using namespace std;

// Const anahtar kelimesinin amacı bir şeyin değerini değiştirilemez yapmak, veya bir fonksiyonu değiştiremez yapmak. (const -> constant diye aklında kalsın)


// Burada x yapılmak istenen şu :
// foo1 fonksiyonu x isimli parametreyi değiştiremez, ancak onun değerini alıp kendi içindeki bir değişkene yazıp onu değiştirebilir.
int foo1(const int& x, int& y) {
    int z = x;
    y++;
    z++;
    return y + z;
}


/*
COMPİLE HATASINI GÖREBİLMEK İÇİN COMMENTLERİ KALDIR
int wrong_foo1 (const int& x, const int& y) {
    x++;
    y++;
    return x + y;
}
*/




//---------------------------------------------------------------------------------------------------------------------------
// Fonksiyonlar da const yapılabilir, ancak const fonksiyonlar sadece class-member fonksiyonlar olabilir.

class myClass {
public:
    int a;
    int b;

    myClass();
    ~myClass();

    int sum() const;
    int increment_and_sum() const;

};

myClass::myClass() {
    a = b = 0;
}


myClass::~myClass() {}


int myClass::sum() const {
    // a++ veya b-- gibi şeyler yasaklanır çünkü bu fonksiyon class değişkenlerini değiştirmeyeceğinin garantisini veriyor
    return a + b;
}


int myClass::increment_and_sum() const {
    int _a = a;
    int _b = b;
    return (++_a) + (++_b);

    /*
    YANLIŞ FONKSİYON TANIMI:
    return (++_a) + (++_b);
    */
}



int main() {
    int m = 3, n = 5;
    int k = foo1(m, n); // m aynı kalacak, ama n 1 artacak
    cout << "m : " << m << " - ";
    cout << "n : " << n << " - ";
    cout << "k : " << k << endl;


    cout << "Now the class..." << endl;
    myClass obj1;
    obj1.a = 7;
    obj1.b = 7;
    cout << obj1.sum() << endl;
    cout << obj1.increment_and_sum() << endl;
    cout << obj1.a << " - " << obj1.b << endl;
    return 0;
}