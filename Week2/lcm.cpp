#include <iostream>
#include "stdint.h"
//long long lcm_naive(int a, int b) {
//  for (long l = 1; l <= (long long) a * b; ++l)
//    if (l % a == 0 && l % b == 0)
//      return l;
//
//  return (long long) a * b;
//}
uint64_t gcd_Euclidean(uint64_t a,uint64_t b)
{
	volatile static uint64_t temp_arrange;
	volatile static uint64_t Modulo,First,Second;

	/* 1- make a is larger*/
	if(b > a)
	{
		temp_arrange = a;
		a = b;
		b = temp_arrange;
	}
	/* 2- modulo a over b , until the modulo gives zero calculate the gcd again*/
	First = a;
	Second = b;
	Modulo = 1;

	while(Modulo > 0)
	{
		Modulo = First % Second;
		First = Second;
		Second = Modulo;
	}
	return First;
}

uint64_t lcm_Euclidean(uint32_t a, uint32_t b)
{
	uint64_t Multiply,Lcm,gcd;

	Multiply = (uint64_t)((uint32_t)a)*((uint32_t)b);
	gcd = gcd_Euclidean(a,b);
	Lcm = Multiply/gcd;
	//std::cout <<"gcd = "<< gcd <<"  Multiply = "<< Multiply << std::endl;

	return Lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_Euclidean(a, b) << std::endl; /* Change before submit*/
  return 0;
}
