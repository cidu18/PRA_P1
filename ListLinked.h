#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "list.h"
#include "Node.h"
const int MINSIZE = 10;

template <typename T>
class ListLinked : public list<T>{

  private:
    Node<T>* first;
    int n;

  public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
       while (first != nullptr){
          Node<T>* aux = first;
          first = first->next;
          delete aux;
       }
    }

    void insert(int pos, T e) override {
       Node<T>* aux = first;
      if(pos < 0 || pos > n){
        throw std::out_of_range("Posición fuera del rango establecido");
        }
      if (pos == 0){
        first = new Node<T>(e,first);
      } else{
        Node<T>* aux = first;
        for(int i = 0; i < pos -1; i++){
          aux = aux->next;
      }
        Node<T>* nuevo = new Node<T>(e, aux->next);
        aux->next = nuevo; 
      

    }
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
        T data_return;
        if(pos == 0){
          Node<T>* del = first; 
          data_return = del->data; 
          first = first->next;
          delete del;
        } else{
          Node<T>* aux = first;
          for(int i = 0; i < pos -1; i++){
            aux = aux->next;
          }
          Node<T>* del = aux->next;
          data_return = del->data;
          aux->next = del->next;
          delete del; 
        }
        n--;
        return data_return; 

        
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        Node<T>* aux = first;
        for(int i = 0; i < pos; i++ ){
            aux = aux->next;
        }
        return aux->data;
                
    }

    int search(T e) override {
      Node<T>* aux = first; 
      int pos = 0;
      while(aux != nullptr){
        if(aux->data == e){
          return pos;
        } else {
          aux = aux->next;
          pos ++;
        }

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

    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
      Node<T>* aux = list.first;   
      out << "[";
        while(aux != nullptr){
          out << aux->data;
          if(aux->next != nullptr) out << ", ";
          aux= aux->next;

        }
        out << "]";
        return out;
    }
};

#endif
