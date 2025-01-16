/*****************************************************************
 * File:   cuenta.h
 * Author: Lucia Morales (816906)
 * Date:   15 febrero 2022
 * Coms:   Ejercicio 2 de Tecnologia de la programacion
*****************************************************************/

#pragma once

class Cuenta{
   protected:
      double capital;
      double interes;

   public:
      //constructor
      Cuenta(double _capital, double _interes) 
      : capital(_capital), interes(_interes){}
      //Funciones
      virtual double valor(int t) const;
      virtual double tae() const;
      virtual void actualiza(int& t);
};

class Plazo : public Cuenta{
   private:
      int plazo;
   public:
      //Constructor
      Plazo(double _capital, double _interes, int _plazo)
      : Cuenta(capital, interes), plazo(_plazo){}
      //Funciones
      double valor(int t) const override;
      double tae() const override;
      void actualiza(int& t) override;
};

class Corriente : public Cuenta{
   public:
      //Constructor
      Corriente(double _capital, double _interes)
       : Cuenta(_capital, _interes){}
      //Funcionees
      double valor(int t) const override;
};

class Nomina : public Cuenta{
   private:
      int ingreso;
   public:
      //Constructor
      Nomina(double _capital, double _interes, int _ingreso) 
      : Cuenta(capital, interes), ingreso(_ingreso){}
      //Funcionees
      double valor(int t) const override;

};

class Divisa : public Cuenta{
   private:
      double factor;
      Cuenta* cuenta;
   public: 
      //Constructor
      Divisa(double _capital, double _factor, Cuenta * _cuenta, double _interes = 0)
      : Cuenta(_capital, _interes), factor(_factor), cuenta(_cuenta){}
      //Funciones
      double valor(int t) const override;
};