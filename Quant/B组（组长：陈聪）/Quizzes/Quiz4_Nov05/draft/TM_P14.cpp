#include <iostream>  
  
using namespace std;  
int max(int a, int b)  
{  
    return a > b ? a : b;  
}  
  
int main()  
{  
    const int N = 3;  
    const int M = 3;  
    int board[N][M];  
    int sum[N][M];  
    int i, j;  
    for (i = 0; i < N; i++)  
    {  
        for (j = 0; j < M; j++)  
        {  
            board[i][j] = rand() % 10;  
            sum[N][M] = 0;  
        }  
    }  
    for (i = 0; i < N; i++)  
    {  
        for (j = 0; j < M; j++)  
        {  
            cout<<board[i][j]<<' ';  
        }  
        cout << endl;  
    }  
    //assume we need to find the max sum for reaching [i][j], then the only sible pathes to get there are from top or left, if we found   
    //optimum sum for reaching [i-1][j] and [i][j-1] we can then decide which one the better way to reach [i][j]  
    sum[0][0] = board[0][0];  
    for (i = 0; i < N; i++)  
    {  
        for (j = 0; j < M; j++)  
        {  
            if (i == 0 && j>0)  
            {  
                sum[i][j] = board[i][j] + sum[i][j - 1];  
            }  
            else if (j == 0 && i>0)  
            {  
                sum[i][j] = board[i][j] + sum[i-1][j];  
            }  
            else if (i > 0 && j>0)  
            {  
                sum[i][j] = board[i][j] + max(sum[i - 1][j], sum[i][j - 1]);  
            }  
        }  
    }  
    cout << sum[i - 1][j - 1];  
}  