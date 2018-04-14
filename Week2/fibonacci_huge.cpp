#include <iostream>
#include "stdint.h"

/*
uint64_t get_fibonacci_huge_naive(uint64_t n, uint64_t m) {
    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;

    for (uint64_t i = 0; i < n - 1; ++i) {
        uint64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
*/

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
	return array[index];
}

int main() {
    uint64_t n, m;
    std::cin >> n >> m;
    std::cout <<get_fibonacci_using_PisanoPeriod(n,m) <<std::endl;//get_fibonacci_huge_naive(n, m) << '\n';
}
