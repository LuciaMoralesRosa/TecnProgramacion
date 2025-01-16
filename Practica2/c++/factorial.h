/*****************************************************************
 * File:   factorial.h
 * Author: Claudia Pavón (852698) y Lucia Morales (816906)
 * Date:   23 febrero 2023
 * Coms:   Declaracion de la clase Factorial, subclase de Programa
*****************************************************************/
#pragma once

#include "programa.h"
#include <iostream>
#include <stack>
#include "add.h"
#include "read.h"
#include "write.h"
#include "push.h"
#include "dup.h"
#include "jumpif.h"
#include "mul.h"
#include "over.h"
#include "swap.h"

using namespace std;

class Factorial : public Programa {
public:
    // Constructor
	Factorial();
};

