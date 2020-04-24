#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;


    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    ~Node() {
        delete prev;
        delete next;
    }

};


// Double LL
class DLL {
private:
    Node *head;
    Node *tail;
    int size;
public:
    DLL() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~DLL() {
        Node *temp1, *temp2;
        if (size == 0) {
            return;
        }
        temp1 = head;
        temp2 = temp1->next;
        for (int i = 0; i < size-1; i++) {
            delete temp1;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        delete temp1;
    }


    void insert(int x, int index) {
        if (index <= size) {
            Node *temp1 = head;
            Node *temp2;
            if (size == 0) {
                head = new Node;
                head->data = x;
                head->prev = NULL;
                head->next = NULL;
                tail = head;
                size++;
            }else if (size == 1) {
                head ->next = new Node;
                tail = head->next;

                tail->prev = head;
                tail->next = NULL;
                tail->data = x;

                size++;
            }else if (index == size) {  //sona ekleme durumu
                tail->next = new Node;
                Node *temp = tail;
                tail = tail->next;

                tail->prev = temp;
                tail->data = x;
                tail->next = NULL;

                size++;
            }else { // size >= 2 ve araya ekleme durumu
                for (int i = 0; i < index-1; i++) {
                    temp1 = temp1->next;
                }
                temp2 = temp1->next;
                Node *new_node = new Node;

                temp1->next = new_node;
                temp2->prev = new_node;

                new_node->prev = temp1;
                new_node->next = temp2;
                new_node->data = x;
                
                size++;}
        }else {
            cout << "Index out of bounds!" << endl;
            return;
        }
    }




    void remove() {

    }

    void print_list() {
        Node *temp = head;
        if (temp == NULL) {
            cout << "The list is empty!" << endl;
        }else {
            while (temp->next != NULL) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
        
    }


};







