
#pragma once

#include"store.h"
using namespace std;


template<typename T>
class StoreAvg : public Store<T>{
    protected:
        int n;
    public:
        StoreAvg(const T& ini = T(0))
        : Store<T>::valor(ini), n(0) , Store<T>::nombre("Average: "){}
        
        void push(const T& data) override { 
            Store<T>::valor += data; 
            ++n;
        }

        const T& value() const override {
            return (n>0) ? (Store<T>::valor/n) : Store<T>::valor;
        }
};

