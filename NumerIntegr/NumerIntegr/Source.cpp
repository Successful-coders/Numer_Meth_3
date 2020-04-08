
#include"Numerical_Integr.h"

int main()
{
	Generate function(sinx);
	NumericalInteg integral(Gauss1);
	double begin = 0, end = 10;
	int segment = 100;

	function.Generate_regularGrid(segment, begin, end);
	function.Func(function.ReturnType());
	std::cout << function.Leib_Integr(function.ReturnType(), begin, end) << "\n";
	//std::cout << integral.Trap(segment,begin, end, function) << "\n";
	//std::cout << fabs(function.Leib_Integr(function.sinx, begin, end) - integral.Trap(segment, begin, end, function)) << "\n";
	//std::cout << 2.812424e-01 << "\n";
	std::cout << integral.NumIntegrAction(segment,begin,end,function) << "\n";
}