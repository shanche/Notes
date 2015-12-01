#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

float MaxProfit(const vector<float>& prices)
{
	float result = 0;

	for (int i = 0; i < prices.size()-1; i++) 
	{
		result += ((prices[i] < prices[i+1])? (prices[i+1] - prices[i]):0);
	}

	return result;
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

	cout<< MaxProfit(prices) << endl;

	return 0;
}