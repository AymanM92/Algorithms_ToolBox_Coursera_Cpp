#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  for(uint16_t i=1 ;0 < n; i++)
  {
	  if(n < 2)
	  {
		  summands.push_back(n);
		  n=0;
	  }
	  else
	  {
		  if( (n-i) >= (i+1) )
		  {
			  summands.push_back(i);
			  n = n-i;
			  //std::cout << "#if - What have been pushed is "<<i<<" and remaining is "<<n<<std::endl;
		  }
		  else
		  {
			  summands.push_back(n);
			  n=0;
			  //std::cout << "#else - What have been pushed is "<<n<<" and remaining is "<<n<<std::endl;
		  }
	  }
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
