#------------------------------------------------------------------------------
# File:   Makefile
# Author: Lucia Morales Rosa
# Date:   7 febrero 2023
# Coms:   Ejercicio 2 de Tecnologia de la programacion 
#         "make all" compilará y generará todos los ejecutables 
#               (alternativamente, "make", sin parámetros)
#         "make clean" borra todo lo genearado, si existe
#------------------------------------------------------------------------------

#---------------------------------------------------------
#definición de variables
CC=g++
CPPFLAGS=-I. -g -std=c++11      #opciones de compilación
LDFLAGS=-pthread             #opciones de enlazado (linkado)
RM=rm -f

all: cuenta main
#-----------------------------------------------------------
# Compilacion
main.o: main.cc
	${CC} -c main.cc ${CPPFLAGS}
#linkado
cuenta: main.o cuenta.o
	${CC} main.o cuenta.o -o cuenta ${LDFLAGS}
cuenta.o: cuenta.cc cuenta.h
	${CC} -c cuenta.cc ${CPPFLAGS}

clean:
	${RM} main.o main
	${RM} cuenta.o cuenta


