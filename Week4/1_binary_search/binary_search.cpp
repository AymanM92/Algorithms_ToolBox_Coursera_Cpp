#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>       /* ceil */

using std::vector;

/*
 int binarysearch(int len, int a[], int x) {
   int low = 0;
   int high = len - 1;
   while (low <= high) {
      int mid = (low + high) / 2;
      if (a[mid] == x) return mid;
      else if (a[mid] < x) low = mid + 1;
      else high = mid - 1;
   }
   return -1;
}

10 2 3 4 5 6 7 8 9 10 11
12 1 2 3 4 5 6 7 8 9 10 11 12
 * */
int binary_search(const vector<int> &a, int x)
{
	int left = 0, right = (int)a.size();
	//std::cout <<"This is right"<< right <<std::endl;
	//int Return =-1;
	int Median = -1;
	//write your code here
	//std::cout <<std::endl;
	//std::cout <<"Next Iteration for X = "<<x<<" Print Fucken Median = "<<Median<<std::endl;
	//std::cout <<"How Equal!"<<std::endl;
	while( left <= right )
	{
		//std::cout <<" NEW While loop with start = "<<left<<" And End = "<<right;
		Median = ceil((left+right)/2);
		//std::cout <<" And Median = "<<Median<<std::endl;
		if(x == a[Median])
		{
			//std::cout <<"Equal!"<<std::endl;
			return Median;
		}
		else if(x > a[Median])
		{
			left = Median + 1;
			//Median = -1;
			//std::cout <<"Upper Bound Now the new Start = "<<left<<" And End = "<<right<<std::endl;
		}
		else
		{
			right = Median -1;
			//Median = -1;
			//std::cout <<"Lower Bound Now the new Start = "<<left<<" And End = "<<right<<std::endl;
		}
	}

	return -1;
}

int linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << binary_search(a, b[i]) << ' ';
	}
	/*
	std::cin >> m;
	std::cout << binary_search(a, m) << ' ';
	*/
}
