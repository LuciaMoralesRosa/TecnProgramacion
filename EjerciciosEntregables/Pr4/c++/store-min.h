
#pragma once
#include"store.h"

using namespace std;

template<typename T>
class StoreMin : public Store<T>{
    protected: 
        bool first;
    public:
        StoreMin() : Store<T>::nombre("min: "){ first = true; }

        void push(const T& data) override { 
            if (first || (data < Store<T>::valor)) { 
                Store<T>::valor = data; 
                first = false;
            }
        }

        const T& value() const override {
            return Store<T>::valor;
        }
};
