#include <iostream>
#include <random>

using namespace std;


int main()
{

	default_random_engine generator(1010101);
	normal_distribution<double> ndist(0,1);
	for(int i=0;i<10;i++)
		cout << ndist(generator) << endl;

	return 0;
}	

