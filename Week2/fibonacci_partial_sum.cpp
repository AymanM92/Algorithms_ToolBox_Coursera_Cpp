#include <iostream>
#include <vector>
using std::vector;

/*long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}*/


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
	uint64_t from, to;
	uint64_t value_from,value_to;
	std::cin >> from >> to;
	from=from+1;
	to=to+2;
	value_from = get_fibonacci_using_PisanoPeriod(from,10);
	value_to = get_fibonacci_using_PisanoPeriod(to,10);
	if(value_from == 0)
	{
		value_from = 9;
	}
	else
	{
		value_from = value_from -1;
	}

	if(value_to == 0)
	{
		value_to = 9;
	}
	else
	{
		value_to = value_to -1;
	}
	if(value_to < value_from)
	{
		value_to = value_to + 10;
	}
	else
	{

	}
	std::cout <<value_to - value_from<< '\n';
	//std::cout <<"value_to ="<< value_to << '\n';
}
