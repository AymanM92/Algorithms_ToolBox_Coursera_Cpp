#include <iostream>

int main()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	std::cin >> a;
	std::cin >> b;
	if((a<=9)&&(b<=9))
	{
		sum = a + b;
		std::cout << sum;
	}
	else
	{
		std::cout << "a and b should be less than 9";
	}

	return 0;
}
