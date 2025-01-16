#include "store-last.h"
#include <iostream>
#include <complex>

int main()
{
    {
        StoreLast<int> s;
        s.push(42);
        s.push(0);
        s.push(15);
        std::cout << s.value() << std::endl;
    }
    {
        StoreLast<double> s;
        s.push(42.3);
        s.push(0);
        s.push(15.2);
        std::cout << s.value() << std::endl;
    }
    {
        StoreLast<std::complex<float>> s;
        s.push(std::complex<float>(42.3, 0));
        s.push(std::complex<float>(0));
        s.push(std::complex<float>(15.2, -1.0));
        std::cout << s.value() << std::endl;
    }
}
