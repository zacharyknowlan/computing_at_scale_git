all: assignment0

assignment0: assignment0_driver.o mult.o mat.o vec.o
	g++ -o assignment0 assignment0_driver.o mult.o mat.o vec.o

assignment0_driver.o: assignment0_driver.cpp
	g++ -c assignment0_driver.cpp

mult.o: mult.cpp
	g++ -c mult.cpp

mat.o: mat.cpp
	g++ -c mat.cpp

vec.o: vec.cpp
	g++ -c vec.cpp

clean:
	rm -rf assignment0_driver.o mult.o mat.o vec.o
