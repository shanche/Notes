#include <iostream>     
#include <algorithm>    
#include <vector>       

class stock {
public: 
	bool closing(int M, int N, std::vector<float> &price, float P); 
};

bool stock::closing(int M, int N, std::vector<float> &price, float P) {
	// store stock prices in a max heap
	std::make_heap (price.begin(),price.end());
	// use res to compute the average of largest M closing prices 
	float res = 0.0; 
	for (int i =0; i < M; ++i) {
		// extract the max elememt and add it to res
		res = res + (float)price.front();
		std::pop_heap (price.begin(),price.end()); 
		price.pop_back();
	}
	res = res / (float)M;
	// compare average of the largest M closing price and P
	if (res <= P) return true;
	else return false;
}
      
int main () {
	stock s;
	int M = 2, N = 5;	
	float P = 10.0;
	float num1[] = {1.0,2.0,3.0,5.0,15.0};
	float num2[] = {1.0,2.0,3.0,7.0,15.0};
    std::vector<float> price1(num1,num1+5);
    std::vector<float> price2(num1,num2+5); 
    bool x = s.closing(M, N, price1, P);
    bool y = s.closing(M, N, price2, P);
    std::cout << "The first stock is: " << x << '\n';
    std::cout << "The second stock is: " << y << '\n'; 
    return 0;
}



 

