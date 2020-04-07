#pragma once
#include "Point.h"
#include "Function.h"

class NumericalInteg
{
public :
	double GaussScheme1(const double& begin, const double& end);
	double GaussScheme4(const double& begin, const double& end);
	double GaussScheme5(const double& begin, const double& end);
	double Trap(const int& segm,  const double& begin, const double& end, Generate function);
	double Simpson(const double& begin, const double& end);
};