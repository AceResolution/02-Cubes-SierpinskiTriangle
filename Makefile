all: bin/01-Cubes bin/01a-Cubes bin/01b-Cubes-Rotate

bin/01-Cubes: src/01-Cubes.cpp
	g++ src/01-Cubes.cpp -lglut -lGL -lGLU -o bin/01-Cubes

bin/01a-Cubes: src/01a-Cubes.cpp
	g++ src/01a-Cubes.cpp -lglut -lGL -lGLU -o bin/01a-Cubes

bin/01b-Cubes-Rotate: src/01b-Cubes-Rotate.c
	g++ src/01b-Cubes-Rotate.c -lglut -lGL -lGLU -o bin/01b-Cubes-Rotate
