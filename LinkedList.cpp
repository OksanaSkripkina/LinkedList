#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next = nullptr;

};

template <typename T>
class LinkedList {
    Node<T>* head = nullptr;
    int counter = 0;
public:
    LinkedList() {}
    LinkedList(T& object) {
        Node<T>* node = new Node<T>{ object };
        head = node;
        counter++;
    }
    void addToHead(T& object) {
        Node<T>* node = new Node<T>{ object, head };
        head = node;
        counter++;
    }
    void addToTail(T& object) {
        Node<T>* buf = head;
        while (buf->next != nullptr) {
            buf = buf->next;
        }
        buf->next = new Node<T>{ object };
        counter++;
    }
    void deleteFromHead() {
        if (counter != 0) {
            Node<T>* buf = head;
            head = head->next;
            delete buf;
            counter--;
        }
    }
    void deleteFromTail() {
        if (counter != 0) {
            Node<T>* buf = head;
            while (buf->next->next != nullptr) {
                buf = buf->next;
            }
            delete buf->next;
            buf->next = nullptr;
            counter--;
        }
    }
    void deleteAll() {
        while (counter != 0) {
            deleteFromHead();
        }
        head = nullptr;
    }



    void show() {
        if (counter != 0) {
            Node<T>* buf = head;
            while (buf->next != nullptr) {
                cout << buf->value << ", ";
                buf = buf->next;
            }
            cout << buf->value << endl;
        }
    }
};



template <typename T>
struct Node2 {
    T value;
    Node2* next = nullptr;
    Node2* prev = nullptr;

};

template <typename T>
class LinkedList2 {
    Node2<T>* head = nullptr;
    Node2<T>* tail = nullptr;
    int counter = 0;
public:
    LinkedList2() {}
    LinkedList2(T& object) {
        Node2<T>* node = new Node2<T>{ object };
        head = node;
        tail = node;
        counter++;
    }
    void addToHead(T& object) {
        if (counter == 0) {
            Node2<T>* node = new Node2<T>{ object };
            head = node;
            tail = node;
            counter++;
        }
        else {
            Node2<T>* node = new Node2<T>{ object, head };
            head->prev = node;
            head = node;
            counter++;
        }
    }
    void addToTail(T& object) {
        if (counter == 0) {
            Node2<T>* node = new Node2<T>{ object };
            head = node;
            tail = node;
            counter++;
        }
        else {
            Node2<T>* node = new Node2<T>{ object, nullptr, tail };
            tail->next = node;
            tail = node;
            counter++;
        }
    }
    void deleteFromHead() {
        if (counter != 0) {
            //Node2<T>* buf = head;
            if (counter == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                counter--;
            }
            else {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
                counter--;
            }
        }
    }
    void deleteFromTail() {
        if (counter != 0) {
            if (counter == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                counter--;
            }
            else {
                Node2<T>* buf = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete buf;
                counter--;
            }
        }
    }
    void deleteAll() {
        while (counter != 0) {
            deleteFromHead();
        }
        head = nullptr;
    }



    void show() {
        if (counter != 0) {
            Node2<T>* buf = head;
            while (buf->next != nullptr) {
                cout << buf->value << ", ";
                buf = buf->next;
            }
            cout << buf->value << endl;
        }
    }
};


class Man {
private:
    string name;
    int age;
public:
    Man(string name, int age) {
        this->name = name;
        this->age = age;
    }
    friend ostream& operator <<(ostream& out, Man& man) {
        out << man.name << " " << man.age;
        return out;
    }
};


int main()
{
    Man man1("Tom", 20);
    Man man2("Henry", 30);
    Man man3("Pet", 40);
    Man man4("Mat", 50);
    LinkedList<Man> list1;

    list1.addToHead(man1);
    list1.addToHead(man2);
    list1.addToHead(man3);
    list1.addToTail(man4);
    list1.show();
    list1.deleteFromHead();
    list1.show();
    list1.deleteFromTail();
    list1.show();
    list1.deleteAll();
    list1.show();
    LinkedList2<Man> list2;
    list2.addToHead(man1);
    list2.addToHead(man2);
    list2.addToHead(man3);
    list2.addToTail(man4);
    list2.show();
    list2.deleteFromHead();
    list2.show();
    list2.deleteFromTail();
    list2.show();
    list2.deleteAll();
    list2.show();
}

