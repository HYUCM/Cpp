#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int _data) {
        data = _data;
        next = NULL;
    }

    Node(int _data, Node* _next) {
        data = _data;
        next = _next;
    }

    ~Node() {
        delete next;
    }

};


// Single LL, Singly LL
class Linked_List {
private:
    Node *head;
    int size;
public:
    Linked_List() {
        head = NULL;
        size = 0;
    }

    Linked_List(int _data) {
        head = new Node;
        head->data = _data;
        head->next = NULL;
        size = 1;
    }


    ~Linked_List() {
        Node *temp1, *temp2;
        
        if (head == NULL) {
            return;
        }else {
            temp1 = head;
            temp2 = head->next;

            while (temp2 != NULL) {
                delete temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }

            delete temp1;
        }
    }

    void insert(int x) {
        Node *temp = head;
        if (head == NULL) {
            head = new Node;
            head->data = x;
            head->next = NULL;
        }else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new Node;
            temp = temp->next;

            temp->data = x;
            temp->next = NULL;
        }
        size++;
    }

    void remove() {
        Node *temp = head;
        if (head == NULL) { // 0 Node
            return;
        }else if (head->next == NULL) { // 1 Node
            delete head;
            head = NULL;
        }else {     //1'den fazla Node
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
	size--;
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