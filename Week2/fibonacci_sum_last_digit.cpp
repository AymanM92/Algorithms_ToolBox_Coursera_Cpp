#include <iostream>
#include "stdint.h"
#include "math.h"
#include <bitset>

#define SquareRootFive (pow(5,0.5))
#define PosExpression  ((1.0+SquareRootFive)/2.0)
#define NegExpression  ((1.0-SquareRootFive)/2.0)


uint64_t get_fibonacci_using_PisanoPeriod(uint64_t n ,uint8_t m)
{
	static volatile uint64_t array[100];
	uint64_t size;
	uint64_t i,index;
	bool Condition;

	array[0]= 0;
	array[1]= 1;

	i=2 ;

	Condition = 1;

	do /*Calculate the Fibonacci to get the period*/
	{
		array[i] = (array[i-1] + array[i-2])%m;
		size = i;
		Condition = !((array[i]==1) && (array[i-1]==0));
		i++;
	}while(Condition); /* use while loop please !!*/

	size--;
	index = n % size;
	//std::cout <<"index = "<<index<<std::endl;
	//std::cout <<"array[index] = "<<array[index]<<std::endl;
	return array[index];
}

/*
int fibonacci_sum_naive(long long n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current  = 1;
	long long sum      = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current%10;
		current = (tmp_previous + current)%10;
		sum += current;
	}

	return sum % 10;
}
 */

/*long double fibonacci_sum_naive(uint64_t n)
{
	long double Fiboncacci= 0;

	if(n == 2)
	{
		return 2;
	}

	Fiboncacci = (1.0/SquareRootFive) * ( (pow(PosExpression,n+2)) - (pow(NegExpression,n+2)) );
	std::cout <<" " << Fiboncacci <<" ";
	return Fiboncacci;//% 10;
}*/

int main() {
	uint64_t n,m = 0;
	uint64_t value;
	std::cin >> n;
	m=n+2;
	value = get_fibonacci_using_PisanoPeriod(m,10);
	if(value == 0)
	{
		std::cout << 9;
	}
	else
	{
		std::cout << value-1;
	}
}


