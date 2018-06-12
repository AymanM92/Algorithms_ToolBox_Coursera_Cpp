#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <list>

using std::vector;

vector<int> optimal_sequence(int n)
{
	std::vector<int> sequence;
	vector<int> MinNumOpr(n+1,INT_MAX);
	vector<int> Path(n+1);

	if(n==1 || n==0)
	{
		sequence.push_back(n);
		return sequence;
	}

	MinNumOpr[0] = 0;
	MinNumOpr[1] = 0;

	for (int i = 2 ; i <= n ; i++)
	{
		MinNumOpr[i] = MinNumOpr[i-1] + 1;
		Path[i]= i-1;
		if (i % 3 == 0)
		{
            if (MinNumOpr[i/3] < MinNumOpr[i])
            {
            	MinNumOpr[i] = MinNumOpr[i/3] + 1;
            	Path[i] = i/3;
            }
		}
		else if (i % 2 == 0)
		{
            if (MinNumOpr[i/2] < MinNumOpr[i])
            {
            	MinNumOpr[i] = MinNumOpr[i/2] + 1;
            	Path[i] = i/2;
            }
		}

	}

    for (int32_t j=n  ;   j != 0  ; j=Path[j])
    {
        sequence.push_back(j);
    }
	//sequence.push_back(n);
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
