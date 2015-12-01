#include <stdlib.h>
#include <iostream>

using namespace std;

double expx(double x)
{
	int i=1;
	int power=1;
	while (x > 1||x<-1)
	{
		x = x / 10;
		power*=10;
	}
	double result = 0;
	double nplus1 = 1;
	
	while (((nplus1 > numeric_limits<double>::min()) && 
	      (nplus1<numeric_limits<double>::max())) || 
		   ((nplus1 < -numeric_limits<double>::min()) && 
		    (nplus1>-numeric_limits<double>::max())))
	{
		nplus1 = nplus1*x / i;
		result += nplus1;
		i++;
	}
	return pow(result + 1, power);
}

int main()
{
	double x = -500;
	char wait;
	cout.precision(40);
	cout << expx(x) << endl;
	cin >> wait;
}