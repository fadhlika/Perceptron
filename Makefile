Perceptron: main.cpp Perceptron.cpp
	clang++ main.cpp Perceptron.cpp -o Perceptron --std=c++11

run: Perceptron
	./Perceptron
