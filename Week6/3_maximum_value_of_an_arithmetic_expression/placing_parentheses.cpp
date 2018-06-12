#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "stdint.h"
#include <cstring>
#include <climits>
#include <cmath>
using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op)
{
	if (op == '*')
	{
		return a * b;
	}
	else if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	} else
	{
		assert(0);
	}
}

long long get_maximum_value(const string &exp)
{
	int length = exp.size();
	int NumLen = (length + 1) / 2;
	long long MinV[NumLen][NumLen];
	long long MaxV[NumLen][NumLen];
	int j=0;
	std::string::size_type sz;
	//write your code here
	for(int idx = 0;idx<NumLen;idx++)
	{
		for(int idy = 0;idy<NumLen;idy++)
		{
			MaxV[idx][idy]=0;
			MinV[idx][idy]=0;
		}
	}

	for(int x=0;x<NumLen;x++)
	{
		//		sz =2*x;
		//		MinV[x][x]=std::stoi(exp,&sz);
		//		MaxV[x][x]=std::stoi(exp,&sz);
		MinV[x][x] = std::stoll(exp.substr(2*x,1));
		MaxV[x][x] = std::stoll(exp.substr(2*x,1));
	}

	for (int s = 0; s < NumLen - 1; s++)
	{
		for (int i = 0; i < NumLen - s - 1; i++)
		{

			int64_t Min = LLONG_MAX;
			int64_t Min1 = LLONG_MAX;
			int64_t Min2 = LLONG_MAX;
			int64_t Min3 = LLONG_MAX;
			int64_t Max1 = LLONG_MIN;
			int64_t Max2 = LLONG_MIN;
			int64_t Max3 = LLONG_MIN;
			int64_t Max = LLONG_MIN;

			j = i + s + 1;

			for(int l=i ; l < j ; l++)
			{
				long long a = eval(MinV[i][l],MinV[l + 1][j],exp[2 * l + 1]);
				long long b = eval(MinV[i][l],MaxV[l + 1][j],exp[2 * l + 1]);
				long long c = eval(MaxV[i][l],MinV[l + 1][j],exp[2 * l + 1]);
				long long d = eval(MaxV[i][l],MaxV[l + 1][j],exp[2 * l + 1]);
				//Min = min(Min,min(a,min(b,min(c,d))));
				//Max = max(Max,max(a,max(b,max(c,d))));
				Min1=min(a,b);
				Min2=min(c,d);
				Min3=min(Min1,Min2);
				Min=min(Min,Min3);
				Max1=max(a,b);
				Max2=max(c,d);
				Max3=max(Max1,Max2);
				Max=max(Max,Max3);
			}
			MinV[i][j] = Min;
			MaxV[i][j] = Max;
		}
	}

	return MaxV[0][NumLen-1];
}

int main() {
	string s;
	std::cin >> s;
	std::cout << get_maximum_value(s) << '\n';
}
