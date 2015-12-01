#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void updateBin(vector<int>* bins, float data, float* endoBin,float step)
{
	int i=0;//aditional bins needed to be added.
	if (data > *endoBin)
	{
		i = (data - *endoBin) / step;
		*endoBin = i>0?data:*endoBin;
		while (i > 0)
		{
			(*bins).push_back(0);
			i--;
		}
		(*bins).back()++;
	}
	else
	{
		int mid, upper, lower;
		lower = 0;
		upper = (*bins).size();
		mid = (upper + lower) / 2;

		while (upper - lower > 1)
		{
			lower = data >= mid*step ? mid : lower;
			upper = data > mid*step ? upper : mid;
			mid = (upper + lower) / 2;
		}
		(*bins)[lower]++;
	}
	

}
float binMedian(float data, vector<int>* bins, 
                float step,float* endoBin,int n)
{
	int i=0;
	int count = 0;
	updateBin(bins, data, endoBin, step);
	if (n == 1)
	{
		cout << "The approximate median of first " << n 
		      << " item is " << data << endl;
		return 0;
	}

	while (count < n / 2 )
	{
		count += (*bins)[i];
		i++;
	}

	if (n % 2 == 0)
	{
		int j = i;
		while (count < n / 2 + 1)
		{
			count += (*bins)[j];
			j++;
		}
		cout << "The approximate median of first " << n 
		     << " item is "  << (i+j)*step*0.5-step << endl;
	}
	else
	{
		while (count < n / 2 + 1)
		{
			count += (*bins)[i];
			i++;
		}
		cout << "The approximate median of first " << n 
		     << " item is " << (i - 1)*step << endl;
	}
	return 0;
}

int main()
{
	vector<int> bins;
	bins.push_back(0);
	float endoBin = 0;
	float* streams;
	float step = 1;
	int N = 10;
	streams = new float[N];
	int i;
	streams[0] = 0;

	for (i = 1; i < N; i++)
	{
		streams[i] = streams[i-1]+step;
	}
	i = 0;
	while (i < N)
	{
		binMedian(streams[i], &bins, step,&endoBin,i + 1);
		i++;
	}
	char wait;
	cout << "Done" << endl;
	cin >> wait;
}