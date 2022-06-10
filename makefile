

CC = g++
CFLAGS = -x c++ -o $@ -c -Wall -Werror

OBJS = obj/main.o obj/addition.o obj/tools.o \
	obj/soustraction.o obj/division.o \
	obj/multiplication.o obj/aide.o obj/variables.o \
	obj/analyseParametres.o
OBJTST = tests/testMain.o tests/testTools.o obj/variables.o

CALC = bin/calculatriceGrandsNombres
TEST = bin/test

calc : $(CALC)

all: $(CALC) $(TEST)
	bin/test

verbose: $(CALC) $(TEST)
	bin/test -v

clean:
	rm obj/* bin/* tests/*.o

$(CALC): $(OBJS)
	$(CC) -o $(CALC) $(OBJS)

$(TEST): $(OBJTST)
	$(CC) -o $(TEST) $(OBJTST)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $^

tests/%.o: tests/%.c
	$(CC) $(CFLAGS) $^

