#include "store-sum.h"
#include <iostream>
#include <complex>

using namespace std;

int main()
{
    {
        StoreSum<int> s;
        s.push(42);
        s.push(0);
        s.push(15);
        cout << s.value() << endl;
    }
    {
        StoreSum<double> s;
        s.push(42.3);
        s.push(0);
        s.push(15.2);
        cout << s.value() << endl;
    }
    {
        StoreSum<complex<float>> s;
        s.push(complex<float>(42.3, 0));
        s.push(complex<float>(0));
        s.push(complex<float>(15.2, -1.0));
        cout << s.value() << endl;
    }
}
