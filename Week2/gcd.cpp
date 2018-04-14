#include <iostream>

//int gcd_naive(int a, int b) {
//	int current_gcd = 1;
//	for (int d = 2; d <= a && d <= b; d++) {
//		if (a % d == 0 && b % d == 0) {
//			if (d > current_gcd) {
//				current_gcd = d;
//			}
//		}
//	}
//	return current_gcd;
//}

int gcd_Euclidean(int a,int b)
{
	volatile static int temp_arrange;
	volatile static int Modulo,First,Second;

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
		//std::cout <<"Modulo="<< Modulo <<"  First="<< First <<" Second="<< Second <<std::endl;
	}
	return First;
}


int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd_Euclidean(a, b) << std::endl;
	return 0;
}
