#pragma once
#include <iostream>
#include "Point.h"
#include <functional>
#include <vector>
enum FUNCTION_TYPE { sinx, xsin1000x, x3, x4, x5 };

class Generate
{
private :

	FUNCTION_TYPE type;

public: 

	Generate(FUNCTION_TYPE function);
	//разбиение сетки
	std::vector<Point> regularGrid;
	// значение функции
	std::vector<double> func_regularGrid;
	void Generate_regularGrid(const double& segm, const double& begin, const double& end);
	
	std::function<double(const Point & P)> Fsinx =[](const Point& P)
	{
		return -cos(P.x());
	};

	std::function<double(const Point & P)> Fxsin1000x =[](const Point& P)
	{
		return (sin(1000*P.x())-(1000*P.x())*cos(1000*P.x()))/1000000;
	};

	std::function<double(const Point & P)> Fx3 = [](const Point& P)
	{
		return P.x() * P.x() * P.x() * P.x() / 4.0;
	};

	std::function<double(const Point & P)> Fx4 = [](const Point& P)
	{
		return P.x() * P.x() * P.x() * P.x() * P.x() / 5.0;
	};

	std::function<double(const Point & P)> Fx5 = [](const Point& P)
	{
		return P.x() * P.x() * P.x() * P.x() * P.x() * P.x() / 6.0;
	};

	//вычисление значения функции
	void Func(FUNCTION_TYPE function);

	double Leib_Integr(FUNCTION_TYPE function, const double& begin, const double& end);

	double FuncInPoint(double x, FUNCTION_TYPE function)
	{
		if (function == sinx)
			return sin(x);
		else if(function == xsin1000x)
			return x * sin(1000 * x);
		else if (function == x3)
			return x * x * x;
		else if (function == x4)
			return x * x * x * x;
		else if (function == x5)
			return x * x * x * x * x;
	}

	FUNCTION_TYPE ReturnType()
	{
		return type;
	}
	
};
  