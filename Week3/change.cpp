#include <iostream>
#include "stdint.h"

#define COINS_10 (10u)
#define COINS_5 (5u)
#define COINS_1 (1u)
#define ZERO 0

int get_change(int m)
{
	uint16_t remaining_value = m;
	int coins_count = 0;

	while(ZERO != remaining_value)
	{
		if(COINS_10 <= remaining_value)
		{
			coins_count++;
			remaining_value = remaining_value -10;
		}
		else if (COINS_5 <= remaining_value)
		{
			coins_count++;
			remaining_value = remaining_value -5;
		}
		else
		{
			coins_count++;
			remaining_value = remaining_value -1;
		}
	}


	return coins_count;
}

int main()
{
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
