#include "Numerical_Integr.h"

//метод Трапеции
double NumericalInteg::Trap(const int& segm, const double& begin, const double& end, Generate function)
{
	double result = 0;
	double sumi = 0;
	
	for (int i = 0; i < segm; i++)
	{
		sumi +=(function.regularGrid[i].x() + function.regularGrid[i + 1].x())
			* function.func_regularGrid[i];
	}
	result = (function.regularGrid[0].x()*function.FuncInPoint(begin, function.sinx) + 
		function.regularGrid[segm].x() * function.FuncInPoint(begin, function.sinx) + sumi)/2;
	//double ost = 0;
	//for (int i = 0; i < segm+1; i++)
	//{
	//	ost += (pow(function.regularGrid[i].x(), 3) / 12) - sin(function.regularGrid[i].x());
	//}
	return result;
}