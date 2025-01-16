#/*****************************************************************
# * File:   Makefile
# * Date:   9 febrero 2023
# * Author: Claudia Pavón (852698) y Lucia Morales (816906)
# * Coms:   Fichero makefile de la implemantacion con TAD
#*****************************************************************/

PROG:=main
SRCS:=rational.cc main.cc

CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

rational.o: rational.cc rational.h
main.o: main.cc rational.h
main.s: main.cc rational.h
