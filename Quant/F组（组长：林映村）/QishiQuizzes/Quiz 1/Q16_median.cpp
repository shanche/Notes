//Estimate the median of streaming data, need  gcc 4.6.3 or up
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>

int N = 100000;		// total number of datas
double AVERAGE = 10;    // parameter for sampling
double STDERROR =2;
/*
----------------------------------------------------------------------------------------------------
The algorithm is from paper:

Raj Jain, Imrich Chlamtac, The P2 algorithm for dynamic calculation of quantiles and histograms without storing observations,
Communications of the ACM, v.28 n.10, p.1076-1085, Oct. 1985  [doi>10.1145/4372.4378].

Here we set p = 0.5, so we get 50th percentile(median) at the center marker position.

----------------------------------------------------------------------------------------------------
*/

using namespace std;

class MarkerPoint{	

  public:

    int n;		//current marker postion(x), count the number of datas less than or equal to q
    double q;		//current estimate value at the Marker position(y)
    double n0;		//desired marker location

    MarkerPoint(int n, double q, double n0): n(n), q(q), n0(n0) {}	// constructor 
};

class Median_Est{

  public:
    vector<MarkerPoint> marker;		//5 marker points
    Median_Est (vector<double>);	//constructor
    void update (double);		//update the location of markers
    void adjust ();		//update the location of markers
};

Median_Est::Median_Est(vector<double> initial_five){

	for(int i =0; i < 5; i++)
		marker.push_back(MarkerPoint(i+1, initial_five[i], i+1));
}

void Median_Est::update(double x){
		
	int k = 0;

	if(x<marker[0].q) {marker[0].q = x; k = 1;} //Find cell k such that qk<= X< qk+i and adjust min/max (q0/q4) if necessary
	else{
		if (marker[0].q<=x && x<marker[1].q) k = 1;
		else{
			if (marker[1].q<=x && x<marker[2].q) k = 2;
			else{
				if (marker[2].q<=x && x<marker[3].q) k = 3;
				else{
					if (marker[3].q<=x && x<=marker[4].q) k = 4;
					else{
						marker[4].q = x; k = 4;
					}
				}
			}
		}
	}

	for( int i = 0; i < 5; i++)
	{
		marker[i].n0 += ((double)i/4.0); //update the desired marker locations if the total number of datas have a increament 1
		if(i >= k) marker[i].n++;
	}

}

void Median_Est::adjust(){

	for(int i = 1; i <= 3; i++){
		double d = marker[i].n0 -marker[i].n;
		if( (d>=1 && (marker[i].n+1)<marker[i+1].n)||(d<=-1 && (marker[i].n-1)>marker[i-1].n)){ // constraint 1: n(i+1) > n(i)
			d = d/abs(d);
			//p2 method: quadratic interpolation using adjacent marker points
			double dq = (d/(marker[i+1].n - marker[i-1].n))*((marker[i].n-marker[i-1].n+d)*(marker[i+1].q-marker[i].q)/(marker[i+1].n-marker[i].n)+(marker[i+1].n-marker[i].n-d)*(marker[i].q-marker[i-1].q)/(marker[i].n-marker[i-1].n));
			if( marker[i].q + dq < marker[i+1].q && marker[i].q + dq > marker[i-1].q) marker[i].q += dq; //constraint 2: q(i+1) > q(i)
			//otherwise, use linear interpolation
			else marker[i].q += (d * (marker[i+d].q - marker[i].q)/(marker[i+d].n - marker[i].n));

			marker[i].n += d;
		}
	}

}


int main()
{
  default_random_engine generator;
  uniform_real_distribution<double> distribution(0, 1.0);
  //normal_distribution<double> distribution(AVERAGE, STDERROR);

  ofstream write("./performance", ios::out); 
  write << "count" << setw(15) << "est median" << setw(15) << "exact median" << setw(15) << "theoretical median" << endl;
  
  vector<double> all_datas;
  
  // first five obeservations
  for(unsigned int i = 0; i < 5; i++) all_datas.push_back(distribution(generator));
  sort(all_datas.begin(), all_datas.end());
  Median_Est median(all_datas);  
  write << "5" << setw(15) << median.marker[2].q << setw(15) << all_datas[2] << setw(15) << 0.5 << endl;
  
  // start from 6th obeservation
  for(unsigned int i = 5; i < N; i++){

	double tmp = distribution(generator);
	all_datas.push_back(tmp);
	
	// sort datas to get the exact median for comparison
  	sort(all_datas.begin(), all_datas.end());
	double exact_median;
	if(i%2 == 0) exact_median = all_datas[(int)(i/2)];	
	else exact_median = (all_datas[(int)(i/2)] + all_datas[(int)(i/2)+1])/2;
	
	// main routine for estimate median
	median.update(tmp);
	median.adjust();
	
	// write result to file
  	write << all_datas.size() << setw(15) << median.marker[2].q << setw(15) << exact_median << setw(15) << AVERAGE << endl;
  }
  
  write.close();
  return 0;
}
