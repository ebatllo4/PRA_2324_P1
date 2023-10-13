#include <iostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}  // Inicializa los miembros en la lista de inicialización.

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first;
            first = first->next;
            delete aux;
        }
        n = 0;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Fuera de rango!");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }
            aux->next = new Node<T>(e, aux->next);
        }
        n++;
    }

    void append(T e) override {
        if (n == 0) {
            first = new Node<T>(e);
        } else {
            Node<T>* aux = first;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = new Node<T>(e);
        }
        n++;
    }

    void prepend(T e) override {
        first = new Node<T>(e, first);
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Fuera de rango!");
        }
        Node<T>* aux = first;
        if (pos == 0) {
            first = aux->next;
        } else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < pos; i++) {
                prev = aux;
                aux = aux->next;
            }
            prev->next = aux->next;
        }
        T e = aux->data;
        delete aux;
        n--;
        return e;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Fuera de rango!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }
            aux = aux->next;
            pos++;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Fuera de rango!");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* aux = list.first;
        out<< "List => [ ";
	while (aux != nullptr) {
            out << aux->data << " ";
            aux = aux->next;
        }
	out<< "]" <<std::endl;
        return out;
    }
};

