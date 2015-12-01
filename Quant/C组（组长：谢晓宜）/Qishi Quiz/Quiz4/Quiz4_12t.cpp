#include<iostream>
#include<vector>

std::vector<int> findLongestDecreasingSubarray_v2(const int* ptr, int len);
void printVector(const std::vector<int>& v2);
void printArray(const int *ptr, int len);

int main()
{
	int seq[] = { 7, 2, 4, 8, 7, 6, 5, 3, 6, 5};

	int length = sizeof seq / sizeof seq[0];
	std::cout << "The Original array is " << std::endl;
	printArray(seq, length);

	std::vector<int> largestDescendingSubarray = findLongestDecreasingSubarray_v2(seq, length);

	std::cout << "The largest Desceding Subarray is" << std::endl;
	printVector(largestDescendingSubarray);
	system("pause");
}


void printVector(const std::vector<int>& v2)
{
	for (unsigned int i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] << ",";
	}
	std::cout << std::endl;
}

void printArray(const int * ptr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << ptr[i] << "," ;  
	}
	std::cout << std::endl;  
}


std::vector<int> findLongestDecreasingSubarray_v2(const int* ptr, int len)
{
	int start = 0;
	int end = 0;
	int largestStart = 0;  // The start of the previous largest subarray
	int largestEnd = 0;    // The end of the previous largest subarray
	int largestLength = largestEnd - largestStart + 1;  // The length of the previous largest subarray
	int currLength = end - start + 1;  // The length of the current subarray

	// The original array is { 7, 2, 4, 8, 7, 6, 5, 3, 6, 5}

	for (int i = 1; i < len; i++)  // use i to loop through the array
	{
		if (ptr[i] < ptr[i - 1])  
		{
			end = i;
			currLength = end - start + 1;
		}
		else
		{
			if (currLength > largestLength)
			{
				largestStart = start;
				largestEnd = end;
				largestLength = currLength;
			}
			start = i;
			end = i;
			currLength = end - start + 1;
		}

		if (i == len - 1)
		{
			if (currLength > largestLength)
			{
				largestStart = start;
				largestEnd = end;
				largestLength = currLength;
			}
		}

	}


	std::vector<int> largestDescendingSubarray;

	for (int i = largestStart; i <= largestEnd; ++i)
	{
		largestDescendingSubarray.push_back(ptr[i]);
	}

	return largestDescendingSubarray;
}
