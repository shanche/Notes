#include <iostream>  
#include <math.h>  
#include <vector>  
  
using namespace std;  
  
void findLDS(vector<double> *arr, vector<int>* table, vector<double>* result)  
{  
    int i, j;  
    int max = 0;  
  
    for (i = 0; i < (*arr).size(); i++)  
    {  
        for (j = 0; j < i; j++)  
        {  
            if ((*arr)[j] > (*arr)[i])  
            {  
                (*table)[i] = (*table)[i]>(*table)[j] + 1 ? (*table)[i] : (*table)[+ 1;  
            }     
        }  
        max = max > (*table)[i] ? max : (*table)[i];  
    }  
  
    for (i = (*table).size() - 1; i >=0; i--)  
    {  
        if ((*table)[i] == max)  
        {  
            (*result).push_back((*arr)[(*arr).size() - i - 1]);  
            max--;  
        }  
    }   
}  
int main()  
{  
    vector<double> arr={5,4,4,3,3,2,2,1,1};  
    vector<int> table(arr.size(), 1 );  
    vector<double> result;  
    int i;  
    findLDS(&arr, &table, &result);  
    for (i = 0; i < table.size(); i++)  
    {  
        cout << table[i] << ',';  
    }  
    cout << endl;  
    for (i = 0; i < result.size(); i++)  
    {  
        cout << result[i] << ',';  
    }  
    return 1;  50.	}  
