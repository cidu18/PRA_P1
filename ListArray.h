#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "list.h"

const int MINSIZE = 10;

template <typename T>
class ListArray : public list<T> {

private:
    T* arr;
    int n;
    int max;

    void resize(int new_size) {
        T* nuevo = new T[new_size];
        int limite = (n < new_size ? n : new_size);
        for (int i = 0; i < limite; i++) {
            nuevo[i] = arr[i];
        }
        delete[] arr;
        arr = nuevo;
        max = new_size;
    }

public:
    ListArray() {
        arr = new T[MINSIZE];
        n = 0;
        max = MINSIZE;
    }

    ~ListArray() {
        delete[] arr;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void prepend(T e) override {
        insert(0, e);
    }

    void append(T e) override {
        insert(n, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        T valor = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (n < max / 4 && max > MINSIZE) {
            resize(max / 2);
        }
        return valor;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) return i;
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
        return get(pos);
    }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};

#endif
