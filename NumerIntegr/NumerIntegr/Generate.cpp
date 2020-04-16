#include "Generate.h"
#include <iomanip>
void Generate::Generate_regularGrid(const int& segm, const double& begin, const double& end)
{
	double h = (end - begin) / segm;
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
	if (function == xsin1000x)
	{
		result = Fxsin1000x(End) - Fxsin1000x(Begin);
	}
	return result;
}

Generate::Generate(FUNCTION_TYPE function)
{
	type = function;
}