#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
/*
9
2 200 100 110 8 1 1

2
1 112
 * */
bool compare0(const string& lhs, const string& rhs) { return lhs[0] > rhs[0]; }
bool compare1(const string& lhs, const string& rhs) { return lhs[1] > rhs[1]; }

std::stringstream ProcessData(vector<string> array)
{
	string a,b,temp;
	std::stringstream Number;
	//bool test;
	/*a = array[0] + array[1];
	b = array[1] + array[0];

	if(std::stoi(a) < std::stoi(b))
	{
		array[0]=b;
		array[1]=a;
	}*/
	//test = (array[0][0] == array[1][0]);
	//std::cout << "Entered the ProcessData Func."<<std::endl;
	for(size_t i = 0; i < array.size(); i++)
	{
		//std::cout << "Entered I for Loop"<<std::endl;

		for(size_t j = i; j < array.size() ; j++)
		{
			//std::cout << "Entered J for Loop print i="<<i<<" j="<<j<<std::endl;
			a = array[i] + array[j];
			b = array[j] + array[i];
			if(std::stoi(a) < std::stoi(b))
			{
				//std::cout << std::stoi(a) <<" "<<std::stoi(b)<<std::endl;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				//std::cout << array[i] <<" "<< array[j] <<std::endl;
			}
		}
		Number << array[i];
	}
	//std::cout <<"This is the out of the func = "<< Number.rdbuf() << std::endl;
	return Number;
	//Apply Swapping to Whole data.
}


std::stringstream largest_number(vector<string> a)
{
	//write your code here
	std::stringstream ret;
	std::sort(a.begin(),a.end(),compare0);
	ret = ProcessData(a); //Sorts the Sting array to be concatinated directly.
//	string result;
//	ret >> result;
	return ret;
}

int main()
{
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout<<largest_number(a).rdbuf();
}
