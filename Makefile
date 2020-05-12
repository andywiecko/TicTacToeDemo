GCC=g++
FLAGS=-O3 -std=c++17 
VERB=-Wall -Werror -Wpedantic

# objects
OBJSRC=$(wildcard src/*.cpp\
				  src/*/*.cpp\
				  src/*/*/*.cpp)
				  
OBJ=$(OBJSRC:.cpp=.o)

main.exe: main.cpp ${OBJ}
	${GCC} -o $@ $^ ${FLAGS} ${VERB}

%.o: %.cpp %.hpp
	$(GCC) -o $@ -c $< ${FLAGS}

.PHONY=clean
clean:
	rm *.exe $(OBJ)