#include <iostream>

using namespace std;

class ClassZ {
private:
    float* list;
    unsigned int size;
public:
    // Empty Constructor
    ClassZ();

    // Constructor
    ClassZ(const float* _list, const int _size);
    
    // Copy Constructor
    ClassZ(const ClassZ& rhs);  // rhs : right hand side (eşitliğin sağ tarafı anlamına geliyor)

    // Move Constructor
    ClassZ(ClassZ&& rhs);

    // Destructor
    ~ClassZ();

    void print_all() const;
};


// Empty Constructor
ClassZ::ClassZ() {
    list = NULL;
    size = 0;
}

// Constructor
ClassZ::ClassZ(const float* _list, const int _size) {
    size = _size;
    
    list = new float[size];
    for (int i = 0; i < size; i++) {
        list[i] = _list[i];
    }
    
}

// Copy Constructor
// Aynı bir önceki constructor gibi, fazladan argüman alıyor bu constructor ve
// argüman olarak da gene aynı class'tan bir nesneye const referans alıyor.
// Bu Copy Constructor'ın amacı 
ClassZ::ClassZ(const ClassZ& rhs) {
    size = rhs.size;

    list = new float[size];
    for (int i = 0; i < size; i++) {
        list[i] = rhs.list[i];
    }

}


// Move Constructor
// Bunun kullanım amacı da bir objenin değerine bir başka objeye aktarmak
// std::move fonksiyonu, ona verdiğin argümanı alıyor, diğer objeye güvenli bir biçimde aktarıyor.
ClassZ::ClassZ(ClassZ&& rhs) {
    list = rhs.list;
    size = rhs.size;
    // şu anda size == rhs.size
    // şu anda list pointer'ı ile rhs.list pointer'ı aynı adresi gösteriyor
    rhs.list = NULL;
    rhs.size = 0;
    // o yüzden rahatlıkla rhs'ın değerlerini istediğimiz başka bir başlangıç değerine geri döndürebiliriz.
}


// Destructor
ClassZ::~ClassZ() {
    delete [] list;
}


void ClassZ::print_all() const {
    if (size == 0) {
        cout << "This class is empty!" << endl;
    }else {
        for (int i = 0; i < size-1; i++) {
            cout << list[i] << " - ";
        }
        cout << list[size-1] << endl;
    }

}

