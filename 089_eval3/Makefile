CFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3
PROGS=cyoa-step1 cyoa-step2 cyoa-step3 cyoa-step4
OBJS=$(patsubst %,%.o,$(PROGS)) page.o story.o
all: $(PROGS)
cyoa-step%: cyoa-step%.o page.o story.o
	g++ -o $@ $^
%.o: %.cpp
	g++ $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *~ $(PROGS) $(OBJS)

page.o: page.h
story.o:story.h

