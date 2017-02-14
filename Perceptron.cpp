#include "Perceptron.h"

using namespace std;

Perceptron::Perceptron(double eta_, int iter_){
	eta = eta_;
	iter = iter_;
}

void Perceptron::fit(vector<vector<double>> traindata_, vector<int> target_){
	traindata = traindata_;
	target = target_;

	vector<double> w_(traindata[0].size() + 1, 0);
	w = w_;

	for(int k = 0; k < iter; k++){
		for(int i = 0; i < traindata.size(); i++){
		double dw = eta * (target[i] - predict(traindata[i]));
		w[0] += dw;
			for(int j = 0; j < w.size(); j++){
				w[j + 1] += dw * traindata[i][j];
			}
		}	
	}
}

int Perceptron::predict(vector<double> X){
	double y = 0;
	for(int i = 0; i < X.size(); i ++){
		y += w[i+1] * X[i];
	}
	y += w[0];
	
	if(y >= 0.0) return 1;
	else return -1;
}
