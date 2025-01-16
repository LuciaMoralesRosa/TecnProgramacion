#include<cstring>
#include<iostream>

using namespace std;

template <typename T>
class Store {
   public:
      T valor;
      string nombre;

   public:
      Store() {}
      
      virtual void push(const T& data) const = 0;

      virtual const T& value() const {
         return valor;
      }
};