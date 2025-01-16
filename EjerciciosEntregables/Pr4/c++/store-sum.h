

#pragma once
#include"store.h"
using namespace std;


template<typename T>
class StoreSum : public Store<T>{
    T sum = 0;
    public:
        StoreSum(const T& ini = 0) : sum(ini), Store<T>::nombre("Sum: ") {}
    //    StoreSum() { sum -= sum; }  //<-- MOLA
        void push(const T& data) override { 
            sum += data; 
        }

        const T& value() const override {
            return sum;
        }
};

