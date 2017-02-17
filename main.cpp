#include <iostream>
#include <fstream>
#include <sstream>
#include "Perceptron.h"

using namespace std;

int main(void){

	cout << "Start Perceptron" << endl;

	cout << "Reading data from file..." << endl;
	//Read data from csv file
	ifstream file("iris.csv");
	stringstream buffer;
	buffer << file.rdbuf();
	
	cout << "Parsing data....." << endl;
	vector<string> lines;
	string token;
	
	while(getline(buffer, token)){
		lines.push_back(token);
	}
	
	cout << "There are " << lines.size() << " of data" << endl;

	vector<vector<double>> data;
	vector<int> y;
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
				if(token == "Iris-setosa")
				{	
					y.push_back(1);
				} else {
					y.push_back(-1);
				}
				row.erase(row.begin(), row.end());
				j = 0;
			}

		}
	}

	//Declare perceptron object
	Perceptron pn = Perceptron(0.1, 10);

	vector<vector<double>> X;
	for(auto row: data){
		vector<double> xi = { row[0],row[2] };
		X.push_back(xi);
	}

	pn.fit(X, y);


	ifstream filevalidate("iris-validasi.csv");
	stringstream buf;
	buf << filevalidate.rdbuf();
	
	cout << "Parsing data....." << endl;
	lines.erase(lines.begin(), lines.end());

	while(getline(buf, token)){
		lines.push_back(token);
	}
	
	cout << "There are " << lines.size() << " of validation data" << endl;

	vector<vector<double>> validatedata;
	vector<int> y_;

	//Insert to vector train data and target
	j = 0;
	for(auto line: lines){
		stringstream ss(line);
		while(getline(ss, token, ',')){
			if(j < 4){
				row.push_back(stod(token));
				j++;
			} else {
				validatedata.push_back(row);
				if(token == "Iris-setosa")
				{	
					y_.push_back(1);
				} else {
					y_.push_back(-1);
				}
				row.erase(row.begin(), row.end());
				j = 0;
			}
		}
	}

	vector<vector<double>> X_;
	for(auto row: validatedata){
		vector<double> xi = { row[0],row[2] };
		X_.push_back(xi);
	}

	int miss = 0;
	for(int l = 0; l < X_.size(); l++){
		if(y_[l] != pn.predict(X_[l])) miss++;
	}

	cout << "Missclassification: " << miss << endl;
	
	return 0;
}
