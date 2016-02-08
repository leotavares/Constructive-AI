#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class V>

class DataValues {
private:
	vector <V> values;
	int classPos = 0;

	void addBias() {
		values.push_back(1);
	}
public:
	//constructors
	DataValues() {
		addBias();
	}
	DataValues(vector <V> val) {
		addBias();
		setValues(val);
	}
	//sets the values as the ones recieved, and add the bias term
	void setValues(vector <V> val) {
		for (int i = 0; i < val.size(); i++)
			values.push_back(val.at(i));
		classPos = values.size() - 1;
	}
	vector <V> getValues() {
		return values;
	}
	int getClassPos() {
		return classPos;
	}
};
