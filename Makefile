CPP = g++
CPPFLAGS = -Wall -std=c++14

all: out

out: main.o
	$(CPP) $(CPPFLAGS) main.o -o out -g

main.o: main.cpp DFA.h.gch
	$(CPP) -c -g $(CPPFLAGS) main.cpp

alphabet.h.gch: alphabet.h
	$(CPP) -c -g $(CPPFLAGS) alphabet.h

DFA.h.gch: DFA.h alphabet.h.gch
	$(CPP) -c -g $(CPPFLAGS) DFA.h

clean:
	rm -f *.o *.gch out
