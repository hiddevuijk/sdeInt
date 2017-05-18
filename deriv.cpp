#include "deriv.h"

#include <iostream>

void deriv::operator() (std::vector<double>& r, std::vector<double>& drdt,
		std::vector<double>& p, std::vector<double>& dpdt, double dt)
{
	int N = r.size();
	double sqrt_dt = std::sqrt(dt);
	double etaX, etaY, etaZ;
	for(int j=0;j<N;j+=3) {
		drdt[j] = v0*p[j]*dt + ndist(generator)*sqrt_dt*sqrt_2Dt;
		drdt[j+1] = v0*p[j+1]*dt + ndist(generator)*sqrt_dt*sqrt_2Dt;
		drdt[j+2] = v0*p[j+2]*dt + ndist(generator)*sqrt_dt*sqrt_2Dt;
		etaX = ndist(generator)*sqrt_dt*sqrt_2Dr;
		etaY = ndist(generator)*sqrt_dt*sqrt_2Dr;
		etaZ = ndist(generator)*sqrt_dt*sqrt_2Dr;
	
		dpdt[j] = (etaY+p[j+2] - etaZ*p[j+1])*sqrt_dt*sqrt_2Dr;
		dpdt[j+1] = (etaZ+p[j] - etaX*p[j+2])*sqrt_dt*sqrt_2Dr;
		dpdt[j+2] = (etaX+p[j+1] - etaY*p[j])*sqrt_dt*sqrt_2Dr;

		r[j] += drdt[j];
		r[j+1] += drdt[j+1];
		r[j+2] += drdt[j+2];

		p[j] += dpdt[j];
		p[j+1] += dpdt[j+1];
		p[j+2] += dpdt[j+2];



	}
}
void deriv::getF()
{
	
}
