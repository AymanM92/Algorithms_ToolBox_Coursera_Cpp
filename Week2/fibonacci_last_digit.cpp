#include <iostream>
#include "math.h"

//#define SR5 pow(5,0.5)
//#define PosRoot ((1+SR5)/2)
//#define NegRoot ((1-SR5)/2)


int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    uint64_t previous = 0;
    uint64_t current  = 1;

    for (int i = 0; i < n - 1; ++i) {
    	uint64_t tmp_previous = (previous % 10);
        previous = (current % 10);
        current = (tmp_previous % 10) + (current % 10);
    }

    return (current % 10);
}

//int get_fibonacci_last_digit_fast(uint64_t n)
//{
//	uint64_t Fibonacci;
//	//uint8_t array[1*10000000];
//
//	Fibonacci = (1/SR5)*(  pow(PosRoot,n)  -  pow(NegRoot,n)  );
//
//	return Fibonacci%10;
//}

//int get_fibonacci_last_digit_fast(uint64_t n)
//{
//	int array[1*10000000];
//
//	array[1]=1;
//	array[0]=0;
//
//	for(uint32_t i=2; i<=n; i++)
//	{
//		array[i] = (array[i-1] + array[i-2])%10;
//	}
//
//	return array[n];
//}


int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    //int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
