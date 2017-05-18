#ifndef GUARD_deriv_h
#define GUARD_deriv_h

#include <cmath>
#include <vector>
#include <random>

struct deriv {
	public:

	deriv(double Dtt, double Drr, double v00,
			std::normal_distribution<double> ndistt,
			std::default_random_engine generatorr) : 
			sqrt_2Dt(std::sqrt(2*Dtt)), sqrt_2Dr(std::sqrt(2*Drr)),
			v0(v00), ndist(ndistt), generator(generatorr){}

	// calculate derivatives, and new positions
	// error if deriv. too large
	void operator() (std::vector<double>& r, std::vector<double>& drdt,
				std::vector<double>& p, std::vector<double>& dpdt, double dt);


	private:
	double L;
	double sqrt_2Dt;
	double sqrt_2Dr;
	double gamma;
	double v0;
	double sigma;
	double epsilon;

	// get force matrix
	void getF();


	// random number generator
	std::default_random_engine generator;
	std::normal_distribution<double> ndist;
};


#endif
