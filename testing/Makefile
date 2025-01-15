all: assignment0_tests

assignment0_tests: assignment0_tester.o mult.o mat.o vec.o tests.o
	g++ -o assignment0_tests assignment0_tester.o mult.o mat.o vec.o tests.o

assignment0_tester.o: assignment0_tester.cpp
	g++ -c assignment0_tester.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

mult.o: ../mult.cpp
	g++ -c ../mult.cpp

mat.o: ../mat.cpp
	g++ -c ../mat.cpp

vec.o: ../vec.cpp
	g++ -c ../vec.cpp

clean:
	rm -rf assignment0_tester.o mult.o mat.o vec.o tests.o
