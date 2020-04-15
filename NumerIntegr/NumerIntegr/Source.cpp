#include"Numerical_Integr.h"
#include <math.h>

std::string Scheme(INTEGR function)
{
	if (function == Gauss1)
		return "Gauss 1";
	if (function == Trap)
		return "Trapeze";
	if (function == Simpson)
		return "Simpson";
}

double Order(const double& leibIntegr, const double& numIntegrH, const double& numIntegrH2)
{
	double value = 0;
	value = 1 + ((numIntegrH2 - numIntegrH) / (leibIntegr - numIntegrH2));
	return log2f(value);
}

int main()
{
	Generate function(sinx);
	NumericalInteg integral(Simpson);
	double begin = 0, end = 1;
	double segment = 100;

	function.Generate_regularGrid(segment, begin, end);
	function.Func(function.ReturnType());

	double lebIntegr = function.Leib_Integr(function.ReturnType(), begin, end);
	double numIntegr = integral.NumIntegrAction(segment, begin, end, function);

	std::cout << "The integration scheme: " << Scheme(integral.ReturnTypeIntegr()) << "\n";
	std::cout << "The Leibniz Integral: " << lebIntegr << "\n";
	std::cout << "Numerical integration: " << numIntegr << "\n";
	std::cout << "Error aproximate " << fabs(lebIntegr - numIntegr) << "\n";
	std::cout << "\n";

	segment = segment * 2;
	function.Generate_regularGrid(segment, begin, end);

	double numIntegrH2 = integral.NumIntegrAction(segment, begin, end, function);
	std::cout << "The integration scheme: " << Scheme(integral.ReturnTypeIntegr()) << "\n";
	std::cout << "The Leibniz Integral: " << lebIntegr << "\n";
	std::cout << "Numerical integration: " << numIntegrH2 << "\n";
	std::cout << "Error aproximate " << fabs(lebIntegr - numIntegrH2) << "\n";
	std::cout << "\n";
	
	std::cout << "The order of approximation: " <<Order(lebIntegr, numIntegr, numIntegrH2)  << "\n";


}