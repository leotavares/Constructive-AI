#pragma once
#include "Perceptron.h"
#include <math.h>

/*Author: Leonardo Tavares Oliveira
Date: 03/03/2016
Description: Implemetation of the pocket algorithm
based on the pseudocode on pag 48 of the book this project
is based (read the README for more info)
*/

using namespace std;

//template for the entrance vector
template <class E>

class Pocket :public Perceptron<E> {
protected:
	vector<float> WPocket;		//weight pocket vector
	int runW = 0;				//how many times the W vector has been evaluated
	int runWPocket = 0;			//how many times the WPocket vector has been evaluated
	long int maxNumOfSteps = 0; //maximum estimated number of steps taken in the evaluation process
	long int numOfSteps = 0;	//number of steps taken in the evaluation process
	vector<bool> randomAux;

	//estimate the number of steps needed to complete the WVector
	void estimateNumOfSteps() {
		maxNumOfSteps = pow(2, EVector.size());
		cout << maxNumOfSteps;
	}

	void resetRandomAux() {
		vector<bool> aux(EVector.size());
		randomAux = aux;
	}

	int getRandomIndex() {
		int index;
		do{
			index = rand() % EVector.size();   //uses random to get a DataValue
		} while (randomAux.at(index) == 1);
		cout << "index: " << index;
		return index;
	}
public:
	Pocket(vector <E> vec) :Perceptron<E>(vec){
		estimateNumOfSteps();
		resetRandomAux();
	}

	decltype(W) generateW() {
		resetW();
		while (numOfSteps<maxNumOfSteps) {
			int index = getRandomIndex();
			if (!evaluateW(EVector.at(index))) {
				adjustW(EVector.at(index));
			}
			numOfSteps++;
		}
		return W;
	}

};
