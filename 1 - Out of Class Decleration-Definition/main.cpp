#include <iostream>
#include "ClassZ.h"


// Bu maini örnek bir cpp programı olsun diye yazıyorum, genişletmekte özgür hisset ;)
int main() {
    // NOT : Empty Constructor'ı kullanmak istiyorsan parantez koyma
    ClassZ obj1;
    
    int size1 = 12;
    int *temp1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        temp1[i] = i*i;
    }
    
    // NOT : Burada normal Constructor'ı kullanacağımızdan parantez içinde argümanları da veriyoruz
    ClassZ obj2(temp1, size1);

    obj1.print_list();
    obj2.print_list();

    return 0;

}