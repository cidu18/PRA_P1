#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>

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

        if (n > max)
            n = max;
    }

public:
    void insert(int pos, T e) const override {
      if(pos > n || pos < 0){
        throw std::out_of_range;
      }else{
        for(int i = n; i > pos; i--){
          arr[i] == arr[i - 1];
        }
        arr[pos] = e;
        n++;


      }
      
    }

    void prepend(T e){
      insert(0,e);
    }
    void append(T e){
      insert(n,e);
    }

    ListArray() {
        arr = new T[MINSIZE];
        n = 0;
        max = MINSIZE;
    }

    ~ListArray() {
        delete[] arr;
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");
        return arr[pos];
    }

    T remove(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        if (n < max / 4 && max > MINSIZE) {
            int nuevo_tam = max / 2;
            if (nuevo_tam < MINSIZE) nuevo_tam = MINSIZE;
            resize(nuevo_tam);
        }
    }

    int size() const  { return n; }
    int capacity() const { return max; }

    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }

    T get(int pos)const override{
      
      if(pos < 0|| pos > max -1){throw std::out_of_range; 
      }else return arr[pos];
    }

    int search(T e){
      for(int i = 0; i > n; i++){
        if(arr[i] == e) return i;
      }
      return -1;
    }
    bool empty() const {
      return n==0;
    }

      

};

#endif

