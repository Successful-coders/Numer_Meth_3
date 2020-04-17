#include "Numerical_Integr.h"

//метод Трапеции
//double NumericalInteg::Trap(const int& segm, const double& begin, const double& end, Generate function)
//{
//	double result = 0;
//	double sumi = 0;
//	
//	for (int i = 0; i < segm; i++)
//	{
//		sumi +=(function.regularGrid[i].x() + function.regularGrid[i + 1].x())
//			* function.func_regularGrid[i];
//	}
//	result = (function.regularGrid[0].x()*function.FuncInPoint(begin, function.sinx) + 
//		function.regularGrid[segm].x() * function.FuncInPoint(begin, function.sinx) + sumi)/2;
//	
//	return result/10;
//}
//
//double NumericalInteg::Trap(const int& segm, const double& begin, const double& end, Generate function)
//{
//
//}

NumericalInteg :: NumericalInteg(INTEGR type1)
{
	switch (type1)
	{
		
	case Gauss1://Work
	{
		type = Gauss1;
		weight = { 2 };
		points = { Point(0, 0, 0) };
		break;
	}
	case Gauss2:
	{
		type = Gauss2;
		weight = { 1,1 };
		points = { Point(-1 / sqrt(3),0,0), Point(1 / sqrt(3),0,0) };
		break;
	}
	case Gauss3:
	{
		type = Gauss3;
		weight = {8.0/9.0, 5.0 / 9.0, 5.0/9.0 };
		points = { Point(0,0,0), Point(sqrt(3 / 5),0,0), Point(-sqrt(3 / 5),0,0) };
		break;
	}
	case Trap://Work
	{
		type = Trap;
		weight = { 1,1 };
		points = { Point(1, 0, 0),Point(-1, 0, 0) };
		break;
	}
	case Simpson://Work
	{
		type = Simpson;
		weight = { 4.0/3.0, 1.0/3.0, 1.0/3.0};
		points = { Point(0, 0, 0),Point(-1, 0, 0),Point(1, 0, 0) };
		break;
	}
	}
}

double NumericalInteg::NumIntegrAction(const int& segm, const double& begin, const double& end, Generate function)
{
	double result = 0;
	double h = (end - begin) / segm;

	for (int i = 0; i < segm; i++)
	{
		for (int k = 0; k < points.size(); k++)
		{
			auto xik = Point((begin + i*h) + (1 + points[k].x()) * h / 2.0, 0, 0);
			result += weight[k] * function.FuncInPoint(xik.x(), function.ReturnType());
		}
	}
	return result*h/2;
}
//INTEGR ReturnTypeIntegr()
//{
//	return type;
//}