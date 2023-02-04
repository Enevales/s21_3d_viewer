SYSTEM:=$(shell uname -s)
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -lgcov --coverage
GLU = -lGL -lGLU -lglut 
CC = gcc
PREF_SRC = ./lib/
SOURCES =  $(wildcard $(PREF_SRC)*.c)

all: 3DViewer
# all, install, uninstall,clean, dvi, dist, tests, gcov_report

3DViewer: 
ifeq ($(SYSTEM), Linux)
	$(CC) `pkg-config --cflags gtk+-3.0` lib/parser.c lib/affine.c lib/graphics.c -o a.out `pkg-config --libs gtk+-3.0` -lm $(GLU)
	./a.out
else ifeq ($(SYSTEM), Darwin)
	$(CC) lib/parser.c lib/graphics.c -o a.out -L/System/Library/Frameworks -framework GLUT -framework OpenGL
	./a.out
endif


style:
	# cppcheck $(SOURCES) $(TESTS) *.h *.c
	cp ../materials/linters/.clang-format ./
	# clang-format -i $(SOURCES)
	clang-format -n $(SOURCES)
	rm -rf .clang-format 

clean:
	rm *.out