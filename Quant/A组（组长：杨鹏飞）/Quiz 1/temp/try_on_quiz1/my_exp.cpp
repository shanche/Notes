#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

class expFunction {
private:
	double my_power(double x, int n);
public:
	expFunction(){};
	~expFunction(){};

	double my_exp(double x);
};

double expFunction::my_power(double x, int n) {
	if (n == 0) {
		return 1.0;
	}

	if (n%2 == 0) {
		return my_power(x, n/2) * my_power(x, n/2);
	} else {
		return x * my_power(x, n/2) * my_power(x, n/2);
	}
}

double expFunction::my_exp(double x)
{
	if (x < 0) {
		return 1.0/my_exp(-x);
	}

	// Round up x when x is large so that
	// e^x = 1 + x + ... + x^n/n! + O(x^n) converges faster.
	int roundup = ceil(x);
	double x_modified = x/roundup;

	double result = 1.0;
	double TaylorExpansionTerm = x_modified;
	int n = 1;
	while (TaylorExpansionTerm > numeric_limits<double>::min()) {
		result += TaylorExpansionTerm;
		TaylorExpansionTerm *= (x_modified/++n);
	}

	return my_power(result, roundup);
}


int main(int argc, char const *argv[]) {
	expFunction soln;

	double power;
	cout << "Input the power: " << endl;
	cin >> power;

	cout << "e^" << power << " = " << soln.my_exp(power) << endl;

	return 0;
}