C_FLAGS = -O3 -Wall

main: main.cpp common.hpp common.cpp
	g++ main.cpp common.cpp $(C_FLAGS) -o $@

clean:
	rm -f *.o main core