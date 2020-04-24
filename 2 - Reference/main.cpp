#include <iostream>

using namespace std;
/* --------------------------REFERANSLAAARRRRR--------------------------
c++'ta referans dediğimiz arkadaş, pointer'ın verdiği verimliliği sağlıyor ve aynı zamanda daha okunabilir ve kolay yazılabilir kod yazmanı sağlıyor.
*/

//---------------------------------------------------------------------------------
// Bu fonksiyon tanımına, fonksiyonu aşağıda çağırırken bak, şimdi bakma.----------
void foo1(int& x) {
    // aynen değişken tanımlamada olduğu gibi, referans tipinden sonra, referans isminden önce & koydun mu olay tamamdır.
    cout << x << endl; 
}
//---------------------------------------------------------------------------------


void foo2(int& y) {
    // şimdi aynı pointerlarda olduğu gibi, referansın gösterdiği değeri bu fonksiyon içinden de değiştirebiliyoruz
    y--;
}







int main() {
    int i = 8;      // i isimli bir int tanımladım
    int &ri = i;    // burada da ri isimli bir değişken tanımladım. Referans işareti &'dir. Aynı pointer tanımında olduğu gibi değişken isminden hemen önce koydum.
    int *pi = &i;   // bu satırdaki &'i referans işareti olan & ile karıştırma sakın. Buradaki hala pointer aritmetiğindeki adres operasyonu.

    cout << i << endl;
    cout << ri << endl;     // referansın gösterdiği değere ulaşmak için bir dereferans operatörüne gerek yok (AMAN TANRIMMMM!!!). Dümdüz yazdık mı referansın ismini işlemimiz oluyor.
    // Pratikte normal bir değişken kullanmaktan farksız (ÇÜNKÜ * KULLANMIYORSUN POİNTER'DAKİ GİBİ)
    // Veeee compiler bu referansı ayyynı bir pointermış gibi kullanıyor amaaa. Yani sanki cout fonksiyonuna i'nin kendisini göndermektense bir pointer gönderiyormuş gibi oluyooor.
    // Ama artık bunlar arka plan detayı ;)
    cout << *pi << endl;

    // referansa yeni bir değer atayarak aslında onun bellekte işaret ettiği konumdaki değeri değiştiriyorsun (aynı pointer gibiiii)
    ri = 7; 
    cout << "referans aracılığıyla değer değiştirildi" << endl;


    cout << i << endl;
    cout << ri << endl;
    cout << *pi << endl;

    *pi = 6;    // hadi bir de pointer'dan değiştirelim
    cout << "pointer aracılığıyla değer değiştirildi" << endl;

    cout << i << endl;
    cout << ri << endl;
    cout << *pi << endl;

    ri = 5;
    // son olarak daaa bu referansı bir fonksiyona nasıl parametre olarak veririz mevzusu.
    // aslında demin cout'u kullanırken orada kullanmış olduk bile
    // peki, bu referansı kabul edecek foknsiyonun parametresi nasıl olmalı? şimdi yukarıdaki tanıma bak :D
    cout << "referans aracılığıyla değer değiştirildi" << endl;
    cout << "foo1 çağırılıyor" << endl;
    foo1(ri);

    cout << "foo2 çağırılıyor" << endl;
    foo2(ri);

    cout << "foo2'den sonra i : " << i << endl;
    
    return 0;
}