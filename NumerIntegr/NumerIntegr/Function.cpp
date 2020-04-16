#include "Function.h"
#include <iomanip>

void Generate::Generate_regularGrid(const double& segm, const double& begin, const double& end)
{
	double h = (end - begin) / segm;
	std::cout <<"h = " <<h << "\n";
	for (double i = begin; i < end; i = i + h)
	{
		regularGrid.push_back(Point(i, 0, 0));
	}
	regularGrid.push_back(Point(end, 0, 0));
}

void Generate::Func(FUNCTION_TYPE function)
{
	if (function == sinx)
	{
		for (int i = 0; i < regularGrid.size(); i++)
		{
			func_regularGrid.push_back(sin(regularGrid[i].x()));
		}
	}
	else if (function == xsin1000x)
	{
		for (int i = 0; i < regularGrid.size(); i++)
		{
			func_regularGrid.push_back(regularGrid[i].x() * sin(1000 * regularGrid[i].x()));
		}
	}
	else if (function == x3)
	{
		for (int i = 0; i < regularGrid.size(); i++)
		{
			func_regularGrid.push_back(regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x());
		}
	}
	else if (function == x4)
	{
		for (int i = 0; i < regularGrid.size(); i++)
		{
			func_regularGrid.push_back(regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x());
		}
	}
	else if (function == x5)
	{
		for (int i = 0; i < regularGrid.size(); i++)
		{
			func_regularGrid.push_back(regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x() * regularGrid[i].x());
		}
	}


}

double Generate::Leib_Integr(FUNCTION_TYPE function, const double& begin, const double& end)
{
	double result = 0;
	auto Begin = Point(begin, 0, 0);
	auto End = Point(end, 0, 0);
	if (function == sinx)
	{
		result = Fsinx(End) - Fsinx(Begin);
	}
	else if (function == xsin1000x)
	{
		result = Fxsin1000x(End) - Fxsin1000x(Begin);
	}
	else if (function == x3)
	{
		result = Fx3(End) - Fx3(Begin);
	}
	else if (function == x4)
	{
		result = Fx4(End) - Fx4(Begin);
	}
	else if (function == x5)
	{
		result = Fx5(End) - Fx5(Begin);
	}

	return result;
}

Generate::Generate(FUNCTION_TYPE function)
{
	type = function;
}