COMPILER=g++

all: main_program test

#main program kompilacja

main_program: main_program.o hello.o libhello.so
	${COMPILER} main_program.o -L. -lhello -o main_program

main_program.o: main_program.cpp
	${COMPILER} -c main_program.cpp -o main_program.o

#test

test: test.o liboperations.a
	${COMPILER} test.o -L. -loperations -o test

test.o: test.cpp
	${COMPILER} -c test.cpp -o test.o

#statyczna biblio

vectors.o: vectors.cpp
	${COMPILER} -c vectors.cpp -o vectors.o

strings.o: strings.cpp
	${COMPILER} -c strings.cpp -o strings.o

liboperations.a: vectors.o strings.o
	ar rcs liboperations.a vectors.o strings.o

#hello biblioteka dynamiczna

hello.o: hello.cpp
	${COMPILER} -c -fPIC hello.cpp -o hello.o

libhello.so: hello.o
	${COMPILER} -shared hello.o -o libhello.so

clean:
	rm -rf main_program main_program.o hello.o
	rm -rf libhello.so
	rm -rf strings.o test.o vectors.o
	rm -rf liboperations.a
	rm -rf test
