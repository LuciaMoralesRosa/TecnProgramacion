

#pragma once

#include"store.h"
using namespace std;

template<typename T>
class StoreMax : public Store<T>{
    protected:
        bool first;
    public:
        StoreMax() : Store<T>::nombre("max: ") { first = true; }

        void push(const T& data) { 
            if (first || (data > Store<T>::valor)) { 
                Store<T>::valor = data; 
                first = false;
            }
        }

        const T& value() const override {
            return Store<T>::valor;
        }
};
