#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using std::vector;

long long max_dot_product(vector<long> a, vector<long> b) {
	// write your code here
	long long result = 0;

	std::sort(a.begin(),a.end());
	std::sort(b.begin(),b.end());

	result = std::inner_product(a.begin(),a.end(),b.begin(),0.0);

	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<long> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b) << std::endl;
}
