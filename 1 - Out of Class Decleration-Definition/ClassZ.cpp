#include <iostream>
#include "ClassZ.h"

/*
Class fonksiyonlarını class dışında tanımlayabilirsin.
Bunu genelde şu şekilde yaparlar:
    private-public şeklinde, fonksiyon ve değişkenleri .h uzantılı header dosyasında deklere edersin, compiler'a aha böyle bir class'ım var dersin.
    Daha sonra .cpp uzantılı bir dosyada da bu header file'ı includelarsın ki daha sonra bu dosyada "böyle bir class yok ki" gibi bir hatayla karşılaşma.
    Son olarak da, class'taki fonksiyonları aynı şu şekilde tanımlarsın:
        return tipi <class ismi>::<fonksiyon ismi>(parametreler(aynı header'daki gibi)) {}
    Sonra da fonksiyonların içeriğini yazarsın.

Burada fonksiyonları hangi sırayla yazdığın farketmez, ama header'daki gibi yazsan okumak açısından daha iyi olur.

Bu class dışı tanımı yapmamızın sebebi de şu : okunabilirliği arttırmak. Çok büyük projelerde devasa class'lar olabiliyormuş. O yüzden bu class'ın ne
özellikleri olduğunu açıp bakmak isteyen biri direkt header'dan okuyup bilgisini alıyor.

------------------------------------------------------------------------------------------------------------
NOT : c++'ta .h yerine .hpp dosyalarıyla da karşılaşabilirsin, aynı şey, farkları yok bildiğim kadarıyla.
------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NOT : Burada karışık bir durum var. main fonksiyonunun olduğu dosyada .h'yi includelayacaksın, ama kodu g++'la derkerken .cpp'yi vereceksin.
      Örnek verecek olursak, bu programı "g++ ClassZ.cpp main.cpp -o Test.out" ile derlersin, ama .cpp'li dosyayı herhangi bir yerde includelamazsın.
      Bu kısımda bir hata yaparsan "multiple definitions of <fonksiyon ismi>" şeklinde bir hatayla karşılaşırsın, ben bu hatayla karşılaştım demin, ondan bu kadar detaylı yazıyorum bunu :D
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


ClassZ::ClassZ() {
    ids = NULL;
    size = 0;
}

ClassZ::ClassZ(int *_ids, int _size) {
    size = _size;

    ids = new int[size];
    for (int i = 0; i < size; i++) {
        ids[i] = _ids[i];
    }
}

ClassZ::~ClassZ() {
    // NOT : dinamik array silerken delete'ten hemen sonra bi [] koy ki delete fonksiyonu bir array sileceğini anlasın
    delete [] ids;
}

bool ClassZ::find(int _id) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == _id) {
            return true;
        }
    }
    return false;
}

int ClassZ::sum_ids() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ids[i];
    }
    return sum;
}

void ClassZ::print_list() {
    if (size == 0) {
        // HATIRLATMA : std = standart library, yanlış bilmiyorsam <iostream> ile birlikte geliyor
        // HATIRLATMA : std::cout yerine cout kullanmak istersen, BU DOSYANIN başına "using namespace std" ekle
        // EK BİLGİ : std::endl yerine '\n' veya "\n" de kullanabilirsin, ama eğer std namespace'inde varsa zaten endl yaz geç bence, daha okunaklı.
        std::cout << "------------" << std::endl;
        std::cout << "Empty Array!" << std::endl;
        std::cout << "------------" << std::endl;
    }else {
        std::cout << "-------------------------------------------" << std::endl;
        for (int i = 0; i < size-1; i++) {
            std::cout << ids[i] << " - ";
        }
        std::cout << ids[size-1] << "\n";
        std::cout << "-------------------------------------------" << std::endl;
    }

}