Perceptron.exe: main.cpp Perceptron.cpp
	g++ main.cpp Perceptron.cpp -o Perceptron.exe -std=c++11

run: Perceptron.exe
	.\Perceptron.exe
