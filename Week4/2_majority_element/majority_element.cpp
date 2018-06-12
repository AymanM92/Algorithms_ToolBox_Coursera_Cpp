#include <algorithm>
#include <iostream>
#include <vector>
#include "stdint.h"

using std::vector;

//int get_majority_element(vector<int> &a, int left, int right) {
//	if (left == right) return -1;
//	if (left + 1 == right) return a[left];
//	uint16_t counter = 0;
//	//write your code here
//	std::sort(a.begin(), a.end());
//
///*
//	if(a.size()<2)
//	{
//		return 1;
//	}
//	else if(a.size()<2)
//	{
//		return !(a[1]-a[0]);
//	}
//*/
//
//	for(uint16_t j=0; j<a.size();j++)
//	{
//		//std::cout <<"a["<<j<<"] = "<<a[j]<<" a["<<j<<"+1] = "<<a[j+1]<<std::endl;
//		if(a[j] == a[j+1])
//		{
//			//std::cout <<"Equal elements, Counter Incremented"<<std::endl;
//			counter++;
//			if(counter+1 > a.size()/2)
//			{
//				//std::cout <<"Counter is Larger than half the array."<<std::endl;
//				return 1;
//			}
//			//std::cout <<"Counter = "<<counter<<std::endl;
//		}
//		else
//		{
//			//std::cout <<"Not Equal, Counter reset!"<<std::endl;
//			counter = 0;
//		}
//
//
//	}
//
//
//	return -1;
//}
bool isMajority(vector<int> &a, int cand)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)

    if (a[i] == cand)
    count++;

    if (count > a.size()/2)
    return 1;

    else
    return 0;
}

int findCandidate(vector<int> &a)
{
    int MajIndex = 0, counter = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[MajIndex] == a[i])
        	counter++;
        else
        	counter--;
        if (counter == 0)
        {
        	MajIndex = i;
        	counter = 1;
        }
    }
    return isMajority(a,a[MajIndex]);
}

/* Function to check if the candidate
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

    if (a[i] == cand)
    count++;

    if (count > size/2)
    return 1;

    else
    return 0;
}




int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	//std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
	std::cout << findCandidate(a) << std::endl;
}
