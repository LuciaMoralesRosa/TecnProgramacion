PROG:=main
SRCS:=programa.cc instruccion.cc main.cc suma.cc cuenta_atras.cc factorial.cc add.cc read.cc write.cc push.cc dup.cc jumpif.cc mul.cc swap.cc over.cc

CXX:= g++ -march=native -O3

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

programa.o: programa.cc programa.h
suma.o: suma.cc suma.h
cuenta_atras.o: cuenta_atras.cc cuenta_atras.h
factorial.o: factorial.cc factorial.h
instruccion.o: instruccion.cc instruccion.h
add.o: add.cc add.h
read.o: read.cc read.h
write.o: write.cc write.h
push.o: push.cc push.h
dup.o: dup.cc dup.h
jumpif.o: jumpif.cc jumpif.h
mul.o: mul.cc mul.h
swap.o: swap.cc swap.h
jumpif.o: over.cc over.h
main.o: main.cc instruccion.h
