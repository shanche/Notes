#include<iostream>
#include<string>

using namespace std;

void reverse(char str[], int start, int end);
void reverseWord(char str[]);

int main()
{
	char str[] = "I am good";
	cout << str << endl;
	reverse(str, 0, strlen(str) - 1);
	cout << str << endl;
	reverseWord(str);
	cout << str << endl;

	system("pause");
}

// reverse a passed-in string
void reverse(char str[], int start, int end)
{
	int len = end - start + 1;
	for (int i = 0; i < len/2; ++i)
	{   
		char tmp = str[start + i];
		str[start + i] = str[end - i];
		str[end - i] = tmp;
	}
}

// reverse each word in a passed-in string
void reverseWord(char str[])
{
	for (int i = 0, left = 0; i < strlen(str); ++i)
	{    
		// if it is not the end of the string
		if (str[i] == ' ')
		{
			reverse(str, left, i - 1);
			left = i + 1;
		}
		// if it is the end of the string
		if (i == strlen(str) - 1)
		{
			reverse(str, left, i);
		}
		
	}
}
