g++compil : *.cpp
	g++ *.cpp -std=c++11 -lSDL2 -lSDL2main -lSDL2_image
run:
	./a.out
