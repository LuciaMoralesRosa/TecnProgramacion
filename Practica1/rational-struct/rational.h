/*****************************************************************
 * File:   rational.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   9 febrero 2023
 * Coms:   Fichero rational.h de la implemantacion con TAD
*****************************************************************/
#pragma once

#include <iostream>


struct Rational;

int mcd(int a, int b);
void reduce(Rational& r);
void init(Rational& r);
void init(Rational& r,int num, int den);
void write(const Rational& r, std::ostream& os);
void read(Rational& r, std::istream& is);

Rational add(const Rational& r1, const Rational& r2);
Rational add(const Rational& r, int i);
Rational add(int i, const Rational& r);

Rational sub(const Rational& r1, const Rational& r2);
Rational sub(const Rational& r, int i);
Rational sub(int i, const Rational& r);

Rational mul(const Rational& r1, const Rational& r2);
Rational mul(const Rational& r, int i);
Rational mul(int i, const Rational& r);

Rational div(const Rational& r1, const Rational& r2);
Rational div(const Rational& r, int i);
Rational div(int i, const Rational& r);

struct Rational{

   friend Rational add(const Rational& r1, const Rational& r2);
   friend Rational add(const Rational& r, int i);
   friend Rational add(int i, const Rational& r);

   friend Rational sub(const Rational& r1, const Rational& r2);
   friend Rational sub(const Rational& r, int i);
   friend Rational sub(int i, const Rational& r);

   friend Rational mul(const Rational& r1, const Rational& r2);
   friend Rational mul(const Rational& r, int i);
   friend Rational mul(int i, const Rational& r);

   friend Rational div(const Rational& r1, const Rational& r2);
   friend Rational div(const Rational& r, int i);
   friend Rational div(int i, const Rational& r);

   friend void init(Rational& r);
   friend void init(Rational& r,int num, int den);

   friend void write(const Rational& r, std::ostream& os);
   friend void read(Rational& r, std::istream& is);   
   friend void reduce(Rational& r);

   private:
      int num;
      char barra;
      int den;   
};
