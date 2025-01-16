
#pragma once
#include"store.h"
using namespace std;


template<typename T>
class StoreLast : public Store<T> {
    //T last;
    public:
        StoreLast() : Store<T>::nombre("last: "){}
        void push(const T& data) { Store<T>::valor = data; }

        const T& value() const override {
            return Store<T>::valor;
        }
};
