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
	case Gauss4: //TO DO, dont work
	{
		type = Gauss4;
		weight = { (18+sqrt(30)/36), (18-sqrt(30)/36), (18 + sqrt(30) / 36), (18 - sqrt(30) / 36) };
		points = {  Point(-sqrt((3-2*sqrt(6/5))/7), 0, 0), 
					Point(sqrt((3 - 2 * sqrt(6 / 5)) / 7), 0, 0),
					Point(-sqrt((3 + 2 * sqrt(6 / 5)) / 7), 0, 0),
					Point(sqrt((3 + 2 * sqrt(6 / 5)) / 7), 0, 0) };
		break;
	}
	case Gauss5:
	{
		type = Gauss5;
		//TO DO
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
		weight = { 4/3, 1/3, 4/3, 1/3 };
		points = { Point(0, 0, 0),Point(-1, 0, 0),Point(1, 0, 0) };
		break;
	}
	}
}

double NumericalInteg::NumIntegrAction(const int& segm, const double& begin, const double& end, Generate function)
{
	double result = 0;
	double h = (end - begin) / segm;

	for (int i = 0; i < segm +1; i++)
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