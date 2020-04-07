
#include"Numerical_Integr.h"

int main()
{
	Generate function;
	NumericalInteg integral;
	double begin = 0, end = 1;
	int segment = 8;

	function.Generate_regularGrid(segment, begin, end);
	function.Func_sinx();
	std::cout << function.Leib_Integr(function.sinx, begin, end) << "\n";
	std::cout << integral.Trap(segment,begin, end, function) << "\n";

}