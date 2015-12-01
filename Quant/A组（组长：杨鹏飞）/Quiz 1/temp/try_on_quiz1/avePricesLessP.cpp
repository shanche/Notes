#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

bool avePricesLessP(const vector<float>& prices, int M, float P)
{
	priority_queue<float> minM;
	for (int i = 0; i < M; i++) 
	{
		minM.push(prices[i]);
	}

	for (int i = M; i < prices.size()-1; i++)
	{
		if (prices[i] < minM.top())
		{
			minM.pop();
			minM.push(prices[i]);
		}
	}

	float total = 0;
	for (int i = 0; i < M; i++)
	{
		total += minM.top();
		minM.pop();
	}
	float avePrices = total/M;

	return avePrices < P;
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	const int size = 10;
	vector<float> prices;
	for (int i = 0; i < size; i++)
	{
		prices.push_back(float(rand())/RAND_MAX);
	}

	for (int i = 0; i < size; i++)
	{
		cout << prices[i] << "    ";
	}
	cout << endl;

	float P = 0.3;
	int M = 4;
	cout << avePricesLessP(prices, M, P) << endl;

	return 0;
}