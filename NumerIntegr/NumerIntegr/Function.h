#pragma once
#include <iostream>
#include "Point.h"
#include <functional>
#include <vector>


class Generate
{
public: 
	//разбиение сетки
	std::vector<Point> regularGrid;
	// значение функции
	std::vector<double> func_regularGrid;
	enum FUNCTION_TYPE { sinx, xsin1000x };
	void Generate_regularGrid(const int& segm, const double& begin, const double& end);
	
	std::function<double(const Point & P)> Fsinx =[](const Point& P) { return -cos(P.x()); };
	std::function<double(const Point & P)> Fxsin1000x =[](const Point& P) 
	{ return (sin(1000*P.x())-(1000*P.x())*cos(1000*P.x()))/1000000; };
	//вычисление значения функции
	void Func_sinx();
	void Func_xsin1000x();

	double Leib_Integr(FUNCTION_TYPE function, const double& begin, const double& end);

	double FuncInPoint(double x, FUNCTION_TYPE function)
	{
		if (function == sinx)
			return sin(x);
		else
			return x * sin(1000 * x);
	}

	
};
  