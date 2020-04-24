#include <iostream>
/*
Bazen tanımladığımız class'ları template olarak tanımlamak isteriz. Bunun sebebi bu class'larda bazı yerlerde birden fazla değişken tipi kullanabilme isteğimiz.
Aşağıdaki ClassA'da da bunu yaptım.
İlk olarak, bir classın template olduğunu belirtmek için class keyword'ünü kullanmadan önce "template <class A1, class A2,........, class An>" şeklinde bir satır koyuyoruz.
Bu satırda A1, A2 falan farklı isimli şablon tipler. Program çalışırken bunlar aynı da olabilir farklı da olabilir. Örneğin:
    template <class T, class F> diye tanımlamış olayım classı. Program çalışırken T=int, F=float falan da olabilir, T=int, F=int de olabilir.
    Birbirinden bağımsız yani onu anlatmaya çalışıyorum.
Daha sonra, bu classın içinde T'yi, F'yi falan gayet normal bir tipmiş gibi kullanabiliyoruz.
Kalan açıklamalar .cpp dosyasında.
*/


template <class T> 
class ClassA {
public:
    T* array;
    int size;

    ClassA();
    ClassA(T *_array, int _size);
    ~ClassA();

    void print();
    T* get_array(); //array'in kendisini dönmeyecek, kopyasını dönecek
};