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
	if (function == Gauss2)
		return "Gauss 2";
	if (function == Gauss3)
		return "Gauss 3";
}

double Order(const double& leibIntegr, const double& numIntegrH, const double& numIntegrH2)
{
	double value = 0;
	value = 1 + ((numIntegrH2 - numIntegrH) / (leibIntegr - numIntegrH2));
	return log2f(value);
}

int main()
{
	Generate function(x5);
	NumericalInteg integral(Gauss3);
	double begin = 0, end = 1;
	double segment = 100;

	function.Generate_regularGrid(segment, begin, end);
	function.Func(function.ReturnType());

	double I, Ih, Ih2;
	I = function.Leib_Integr(function.ReturnType(), begin, end);

	Ih = integral.NumIntegrAction(segment, begin, end, function);
	std::cout << "The integration scheme: " << Scheme(integral.ReturnTypeIntegr()) << "\n";
	std::cout << "I: " << I << "\n";
	std::cout << "Ih: " << Ih << "\n";
	double diff_I_Ih = I - Ih;

	segment *= 2;
	function.Generate_regularGrid(segment, begin, end);

	Ih2 = integral.NumIntegrAction(segment, begin, end, function);
	std::cout << "Ih2: " << Ih2 << "\n";
	double diff_I_Ih2 = I - Ih2;
	std::cout << "I - Ih2: " << diff_I_Ih2 << "\n";

	double k = log2f(abs(1 + (Ih2 - Ih) / diff_I_Ih2));
	std::cout << "k: " << k << "\n";

	double quotient = (I - Ih) / (I - Ih2);
	double quotient2 = (Ih2 - Ih) / (powf(2.0, k) - 1.0);
	double IR = Ih2 + quotient2;
	double diff_I_IR = I - IR;

	std::cout << "\n\n";
	std::cout << "I - Ih: " << diff_I_Ih << "\n";
	std::cout << "quotient: " << quotient << "\n";
	std::cout << "quotient2: " << quotient2 << "\n";
	std::cout << "IR: " << IR << "\n";
	std::cout << "I - IR: " << diff_I_IR << "\n";
	std::cout << "\n";
}