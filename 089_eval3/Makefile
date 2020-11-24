CCFLAGS=--std=gnu++11 -pedantic -Wall -Werror -ggdb3
cyoa-step1: page.o cyoa-step1.o
	g++ -o cyoa-step1 $(CCFLAGS) page.o cyoa-step1.o

%.o: %.cpp page.h
	g++ -c $(CCFLAGS) $<

clean:
	rm -f *.o  *~ cyoa-step1