#pragma once
#include "Point.h"
#include "Function.h"

enum INTEGR { Gauss1, Gauss4, Gauss5, Gauss6, Trap, Simpson };
class NumericalInteg 
{
private:
	
	std::vector<Point> points;
	std::vector<double> weight;
public :
	INTEGR type;
	NumericalInteg(INTEGR type);

	INTEGR ReturnTypeIntegr()
	{
		return type;
	}
	
	double NumIntegrAction(const int& segm, const double& begin, const double& end, Generate function);
};