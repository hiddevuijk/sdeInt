#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "deriv.h"

using namespace std;

int main()

{
	int N = 1000;
	vector<double> r(3*N,0.0);
	vector<double> drdt(3*N,0.0);
	vector<double> p(3*N,0.0);
	vector<double> dpdt(3*N,0.0);
	normal_distribution<double> ndist(0,1);
	default_random_engine generator(1000);
	deriv d(.1,.0,.0,ndist,generator);

	for(int i=0;i<1000;++i)
		d(r,drdt,p,dpdt,.1);

	cout << r[0] << endl;	



	return 0;

}

