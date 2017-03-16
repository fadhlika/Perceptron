#include "Perceptron.h"

using namespace std;

Perceptron::Perceptron(double eta_, int iter_){
	eta = eta_;
	iter = iter_;
}

void Perceptron::fit(vector<vector<double>> traindata_, vector<int> target_){
	traindata = traindata_;
	target = target_;

	vector<double> w_(traindata[0].size(), 0);
	w = w_;
	b = 0;

	for(int k = 0; k < iter; k++){
		for(int i = 0; i < traindata.size(); i++){
		double db = eta * (target[i] - predict(traindata[i]));
		b += db;
			for(int j = 0; j < w.size(); j++){
				w[j] += db * traindata[i][j];
			}
		}	
	}
}

int Perceptron::predict(vector<double> X){
	double y = 0;
	for(int i = 0; i < X.size(); i ++){
		y += w[i] * X[i];
	}
	y += b;
	
	if(y >= 0.0) return 1;
	else return -1;
}
