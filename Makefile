all: assignment0

assignment0: assignment0.o mult.o mat.o vec.o
	g++ -o assignment0 assignment0.o mult.o mat.o vec.o
	
assignment0.o: assignment0.cpp
	g++ -c assignment0.cpp

mult.o: mult.cpp
	g++ -c mult.cpp

mat.o: mat.cpp
	g++ -c mat.cpp

vec.o: vec.cpp
	g++ -c vec.cpp

clean:
	rm -rf assignment0 assignment0.o
