#include "ClassZ.cpp"

using namespace std;

// Anlamazsan şu videoya bak : https://www.youtube.com/watch?v=IOkgBrXCtfo
int main() {

    int x = 5;
    float* temp = new float[x];
    for (int i = 0; i < x; i++) {
        temp[i] = i + 0.5;
    }

    cout << "EMPTY CONSTRUCTOR" << endl;
    ClassZ obj1;
    cout << "obj1 : ";
    obj1.print_all();

    cout << "CONSTRUCTOR" << endl;
    ClassZ obj2(temp, x);
    cout << "obj2 : ";
    obj2.print_all();

    cout << "COPY CONSTRUCTOR" << endl;
    ClassZ obj3(obj2);
    cout << "obj2 : ";
    obj2.print_all();
    cout << "obj3 : ";
    obj3.print_all();

    cout << "MOVE CONSTRUCTOR" << endl;
    ClassZ obj4(std::move(obj3));
    cout << "obj3 : ";
    obj3.print_all();
    cout << "obj4 : ";
    obj4.print_all();


    return 0;
}