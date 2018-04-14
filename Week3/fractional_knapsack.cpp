#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*
	std::sort(ValuePerUnit.begin(), ValuePerUnit.end(), std::greater<double>());
	std::cout << "Sorted array :" << std::endl;
	for(int i=0; i<n ; i++)
	{
	std::cout << ValuePerUnit[i].val <<" "<< ValuePerUnit[i].wgt <<" " << ValuePerUnit[i].VpWgt << std::endl;
	}
	std::cout << std::endl;
	std::cout << ValuePerUnit[i].val <<" "<< ValuePerUnit[i].wgt <<" " << ValuePerUnit[i].VpWgt << std::endl;
	std::cout << "Unsorted array :" << std::endl;


*/
struct items
{
	double val;
	double wgt;
	double VpWgt;
};


bool compare(const items& p1, const items& p2)    {    return p1.VpWgt > p2.VpWgt;    }


double get_optimal_value(int capacity, vector<int> weights, vector<int> values ,int n)
{
	// write your code here
	double value = 0.0;
	//int n;
	int index = n;

	vector<items> ValuePerUnit(n);

	for(int i=0; i<n ; i++)
	{
		ValuePerUnit[i].VpWgt = (double) ((double)values[i])/((double)weights[i]);
		ValuePerUnit[i].val = (double)values[i];
	    ValuePerUnit[i].wgt = (double)weights[i];
	    //std::cout << ValuePerUnit[i].val <<" "<< ValuePerUnit[i].wgt <<" " << ValuePerUnit[i].VpWgt << std::endl;
	}
	std::sort(ValuePerUnit.begin(), ValuePerUnit.end(), compare);

	//std::cout << "Sorted array :" << std::endl;
	for(int i=0; i<n ; i++)
	{
	//std::cout << ValuePerUnit[i].val <<" "<< ValuePerUnit[i].wgt <<" " << ValuePerUnit[i].VpWgt << std::endl;
	}

	//std::cout << std::endl;
	//std::cout << std::endl;

	while((0 < capacity) && (0 < index))
	{
		if(capacity > ValuePerUnit[0].wgt)
		{
			capacity = capacity - ValuePerUnit[0].wgt;
			value += ValuePerUnit[0].wgt * ValuePerUnit[0].VpWgt;
			ValuePerUnit.erase(ValuePerUnit.begin());
			index--;
		}
		else if (capacity == ValuePerUnit[0].wgt)
		{
			capacity = capacity - ValuePerUnit[0].wgt;
			value += ValuePerUnit[0].wgt * ValuePerUnit[0].VpWgt;
			ValuePerUnit.erase(ValuePerUnit.begin());
			index--;
		}
		else
		{
			value += (ValuePerUnit[0].VpWgt * capacity);
			ValuePerUnit[0].wgt = ValuePerUnit[0].wgt - capacity;
			capacity = 0;
		}
	}
//	std::cout <<value<< std::endl;
//	std::cout << std::endl;
//	std::cout << std::endl;

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}
	/*std::cout <<"sizeof(weights) in main = " << sizeof(weights) << std::endl;
	std::cout <<"sizeof(weights[0]) in main = " << sizeof(weights[0]) << std::endl;
	std::cout <<"sizeof(values) in main = " << sizeof(values) << std::endl;
	std::cout <<"sizeof(values[0]) in main = " << sizeof(values[0]) << std::endl;*/
	double optimal_value = get_optimal_value(capacity, weights, values, n);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
