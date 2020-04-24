#include <iostream>

class ClassZ {
private:
    int *ids;
    int size;
public:
    // Empty Constructor
    ClassZ();

    // Constructor
    ClassZ(int *_ids, int _size);

    // Destructor
    ~ClassZ();

    bool find(int _id);

    int sum_ids();

    void print_list();
};

