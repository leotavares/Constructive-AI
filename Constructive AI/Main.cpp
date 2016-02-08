#include "Perceptron.h"
#include "DataValues.h"

int main() {
	vector<DataValues<float>> trainingSet;

	/*vector<float> v;
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(-1);
	v.push_back(+1);
	DataValues<float> dv;
	dv.setValues(v);
	trainingSet.push_back(dv);

	v.at(0) = 1;
	v.at(1) = -1;
	v.at(2) = -1;
	v.at(3) = -1;
	DataValues<float> dv1;
	dv1.setValues(v);
	trainingSet.push_back(dv1);

	v.at(0) = 1;
	v.at(1) = 1;
	v.at(2) = 1;
	v.at(3) = 1;
	DataValues<float> dv2;
	dv2.setValues(v);
	trainingSet.push_back(dv2);
	*/

	vector<float> v;
	v.push_back(-1);
	v.push_back(1);
	v.push_back(-1);
	DataValues<float> dv;
	dv.setValues(v);
	trainingSet.push_back(dv);

	v.at(0) = 1;
	v.at(1) = -1;
	v.at(2) = -1;
	DataValues<float> dv1;
	dv1.setValues(v);
	trainingSet.push_back(dv1);

	v.at(0) = 1;
	v.at(1) = 1;
	v.at(2) = 1;
	DataValues<float> dv2;
	dv2.setValues(v);
	trainingSet.push_back(dv2);

	v.at(0) = -1;
	v.at(1) = -1;
	v.at(2) = -1;
	DataValues<float> dv3;
	dv3.setValues(v);
	trainingSet.push_back(dv3);

	Perceptron<DataValues<float>> *firstP = new Perceptron<DataValues<float>>(trainingSet);
	
	firstP->generateW();

	system("PAUSE");
	return 0;
}