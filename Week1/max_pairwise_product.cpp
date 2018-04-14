#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/*
int MaxPairwiseProduct(const vector<int>& numbers) {
	int result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] * numbers[j] > result) {
				result = numbers[i] * numbers[j];
			}
		}
	}
	return result;
} */

/*
 * Using Search Algorithm which is of complexity of the order n
 * not as the last one with an order of n*n
 * */
int64_t MaxPairwiseProduct (const vector<int>& numbers)
{
	int64_t result =0;
	int64_t LargestNum =0;
	int64_t SecondLargeNum =0;
	int n = numbers.size();

	if(n<2)
	{
		cout<<"Wrong argument size n must be >= 2 ."<<endl;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if(numbers[i] > LargestNum)
			{
				SecondLargeNum = LargestNum;
				LargestNum = numbers[i];
			}
			else if(numbers[i] > SecondLargeNum)
			{
				SecondLargeNum = numbers[i];
			}
			else
			{
				/*DoNothing*/
			}
		}
		result = LargestNum*SecondLargeNum;
	}

	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	int64_t result = MaxPairwiseProduct(numbers);
	cout <<result << "\n";
	return 0;
}


