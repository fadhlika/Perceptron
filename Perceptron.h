#include <vector>
#include <iostream>

class Perceptron{
	public:
		Perceptron(double, int);
		void fit(std::vector<std::vector<double>>, std::vector<int>);
		int predict(std::vector<double>);

	private:
		double eta;
		int iter;	
		std::vector<std::vector<double>> traindata;
		std::vector<int> target;
		std::vector<double> w;
};


