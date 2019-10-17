CPP = g++
CPPFLAGS = -Wall -Wextra -Wpedantic -std=c++14

out: main.o
	$(CPP) $(CPPFLAGS) main.o -o out -g

main.o: main.cpp alphabet.hpp
	$(CPP) -c $(CPPFLAGS) main.cpp alphabet.hpp -g
clean:
	rm -f *.o *.gch out
