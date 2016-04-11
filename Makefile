all: bin/01-Cubes bin/01a-Cubes bin/01b-Cubes-Rotate bin/02-Sierpinski-Chaos bin/03-Sierpinski-Removing-Triangle

bin/01-Cubes: src/01-Cubes.cpp
	g++ src/01-Cubes.cpp -lglut -lGL -lGLU -o bin/01-Cubes

bin/01a-Cubes: src/01a-Cubes.cpp
	g++ src/01a-Cubes.cpp -lglut -lGL -lGLU -o bin/01a-Cubes

bin/01b-Cubes-Rotate: src/01b-Cubes-Rotate.c
	g++ src/01b-Cubes-Rotate.c -lglut -lGL -lGLU -o bin/01b-Cubes-Rotate

bin/02-Sierpinski-Chaos: src/02-Sierpinski-Chaos.cpp
	g++ src/02-Sierpinski-Chaos.cpp -lglut -lGL -lGLU -o bin/02-Sierpinski-Chaos

bin/03-Sierpinski-Removing-Triangle: src/03-Sierpinski-Removing-Triangle.cpp
	g++ src/03-Sierpinski-Removing-Triangle.cpp -lglut -lGL -lGLU -o bin/03-Sierpinski-Removing-Triangle

