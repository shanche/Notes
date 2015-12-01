#include <iostream>  
#include <string>  
  
using namespace std;  
  
bool checkPal(string *s)  
{  
	int i=0;  
	while(i<s->length()/2)  
    {  
        if ((*s)[i]==(*s)[s->length()-1-i])  
        {  
            i++;  
        }  
        else  
        {  
            return false;  
        }  
    }  
    return true;  
}  
  
void main()  
{  
    string s("112211");  
    cout<<checkPal(&s)<<endl;  
}  
