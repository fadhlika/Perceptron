#include <iostream>
#include <fstream>
#include <sstream>
#include "Perceptron.h"

using namespace std;

vector<vector<double>> getData(string filename);
vector<int> getTarget(string filename);

int main(void){

	cout << "Start Perceptron" << endl;

	vector<vector<double>> X = getData("iris.csv");
	vector<int> y = getTarget("iris.csv");

	printf("There are %i feature and %i data\n", X[0].size(), y.size());

	//Declare perceptron object
	Perceptron pn = Perceptron(0.1, 10);
	
	pn.fit(X, y);

	vector<vector<double>> X_ = getData("iris-validasi.csv");
	vector<int> y_ = getTarget("iris-validasi.csv");

	printf("There are %i feature and %i data\n", X_[0].size(), y_.size());

	int miss = 0;
	for(int l = 0; l < y_.size(); l++){
		if(y_[l] != pn.predict(X_[l])) 
		{
			miss++;
		}
	}

	cout << "Missclassification: " << miss << endl;
	
	return 0;
}

vector<vector<double>> getData(string filename){
	cout << "Reading data from file..." << endl;
	//Read data from csv file
	ifstream file(filename);
	stringstream buffer;
	buffer << file.rdbuf();
	
	cout << "Parsing data....." << endl;
	vector<string> lines;
	string token;
	
	while(getline(buffer, token)){
		lines.push_back(token);
	}

	vector<vector<double>> data;
	vector<double> row;

	//Insert to vector train data and target
	int j = 0;
	for(auto line: lines){
		stringstream ss(line);
		while(getline(ss, token, ',')){
			if(j < 4){
				row.push_back(stod(token));
				j++;
			} else {
				data.push_back(row);
				row.erase(row.begin(), row.end());
				j = 0;
			}

		}
	}
	return data;
}

vector<int> getTarget(string filename){
	cout << "Reading data from file..." << endl;
	
	//Read data from csv file
	ifstream file(filename);
	stringstream buffer;
	buffer << file.rdbuf();
	
	cout << "Parsing data....." << endl;
	vector<string> lines;
	string token;
	
	while(getline(buffer, token)){
		lines.push_back(token);
	}
	
	vector<int> y;

	//Insert to vector train data and target
	int j = 0;
	for(auto line: lines){
		stringstream ss(line);
		while(getline(ss, token, ',')){
			if(j < 4){
				j++;
			} else {
				if(token == "Iris-setosa")
				{	
					y.push_back(1);
				} else {
					y.push_back(-1);
				}
				j = 0;
			}
		}
	}
	return y;
}