#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N = 26;
    float card[N+1][N+1];    
    card[0][0] = 0;
    for (int i =1; i < N+1; i++) {
       card[i][0] = 0.0;
       card[0][i] = (float) i;
    }
    for (int i = 2; i < 2*N+1; i++) {
        for (int j = 1; j < N+1; ++j) {
            float b = (float) j;
            float tmp = (float) i;
            float r = tmp - b;
            card[j][i-j] = max(r-b,(b * card[j-1][i-j])/(b+r) + 
                           (r * card[j][i-j-1]) / (b+r));
        }
    }
    cout << "E(f(26,26)) is " << card[N][N] << endl;
    return 0;
}