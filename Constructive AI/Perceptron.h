#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>

/*Author: Leonardo Tavares Oliveira
Date: 08/02/2016
Description: Implemetation of the perceptron algorithm
based on the pseudocode on pag 38 of the book this project
is based (read the README for more info)
*/

using namespace std;

//template for the entrance vector
template <class E>

class Perceptron {
protected:
	vector<E> EVector;	//evaluation vector
	int numberOfValues;	//number of values(incl. bias & excl. class) in the DataValues
	//TODO: CHANGE THE WAY THIS WORKS, TO MAKE IT POSSIBLE TO GET VALUE TYPE FROM E
	vector<float> W;	//weight vector
	
	//return true if the current W evaluates all EVector correct
	bool validW() {
		bool valid = true;
		int i = 0;
		while (valid&&i < EVector.size()) {
			if (evaluateW(EVector.at(i)))
				i++;
			else
				valid = false;
		}

		return valid;
	}

	//changes the W based on the currentE
	void adjustW(E currentE) {
		for (int i = 0; i < numberOfValues; i++) {
			W.at(i) += currentE.getValues().at(i)*currentE.getValues().at(currentE.getClassPos());
		}
		for (int i = 0; i < numberOfValues; i++)
			cout << W.at(i) << " ";
		cout << endl;
	}

	//checks if the current W evaluates the currentE correctly
	bool evaluateW(E currentE) {
		float sum = 0;
		for (int i = 0; i < numberOfValues; i++)
			sum += W.at(i)*currentE.getValues().at(i);
		if (sum > 0 && currentE.getValues().at(currentE.getClassPos()) == 1 || sum < 0 && currentE.getValues().at(currentE.getClassPos()) == -1)
			return true;
		return false;
	}

	//resets W to a zero-filled vector
	void resetW() {
		decltype(W) aux(numberOfValues);
		W = aux;
	}

	//debug function
	void printEVector() {
		for (int i = 0; i < EVector.size(); i++) {
			E actualE = EVector.at(i);
			for (int j = 0; j < actualE.getValues().size(); j++)
				cout << actualE.getValues().at(j) << " ";
			cout << endl;
		}
	}

public:
	//constructors
	Perceptron();
	Perceptron(vector <E> vec) {
		setEVector(vec);
	}
	//sets the Evaluation Vector as the one recieved
	void setEVector(vector <E> vec) {
		EVector = vec;
		numberOfValues = EVector.at(0).getValues().size()-1;
		resetW();
		printEVector();
	}
	//main fuction, generates(if possible) a W based on the EVector
	decltype(W) generateW() {
		resetW();
		while (!validW()) {
			int index = rand() % EVector.size();   //uses random to get a DataValue
			if (!evaluateW(EVector.at(index))) {
				adjustW(EVector.at(index));
			}
		}
		return W;
	}
	//sets the weight vector
	void setW(decltype(W) newW) {
		W = newW;
	}
	//returns the weight vector
	decltype(W) getW() {
		return W;
	}
	
};

