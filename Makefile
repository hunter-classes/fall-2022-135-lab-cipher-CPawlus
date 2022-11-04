CXXFLAGS= --coverage -g -O0
main: main.o funcs.o
	g++ -o main --coverage -g -O0 main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests --coverage -g -O0 tests.o funcs.o
	./tests
	gcovr 2> /dev/null > /dev/null
	gcovr --html-details coverage.html

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp funcs.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h
	g++ -c tests.cpp 

clean:
	rm -f main tests main.o funcs.o tests.o *gcda *html *gcno