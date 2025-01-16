#include "store-max.h"
#include <iostream>
#include <complex>

// Si queremos que los números complejos tengan operador > lo tenemos que definir en base a un criterio
//  como este

template<typename Num>
bool operator>(const std::complex<Num>& a, const std::complex<Num>& b) {
    return std::abs(a)>std::abs(b);
}

int main()
{
    {
        StoreMax<int> s;
        s.push(42);
        s.push(0);
        s.push(15);
        std::cout << s.value() << std::endl;
    }

    {
        StoreMax<double> s;
        s.push(42.3);
        s.push(0);
        s.push(15.2);
        std::cout << s.value() << std::endl;
    }

    // Tenemos que comentar esto para que no de un error de compilacion porque std::complex<float> no dispone
    //  del operador >
    {
        StoreMax<std::complex<float>> s;
        s.push(std::complex<float>(42.3,0));
        s.push(std::complex<float>(0));
        s.push(std::complex<float>(15.2,-1.0));
        std::cout<<s.value()<<std::endl;
    }
}
