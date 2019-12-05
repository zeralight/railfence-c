FLAGS=-Wall -std=c++14 -O3
all: encryption decryption
encryption:
	g++ $(FLAGS) -o build/encryption src/encryption.cpp
decryption:
	g++ $(FLAGS) -o build/decryption src/decryption.cpp
tests: encryption decryption
	g++ $(FLAGS) -o build/test1 tsts/test1.cpp
	g++ $(FLAGS) -o build/test2 tsts/test2.cpp
	build/test1
	build/test2
clean:
	rm -f build/*
