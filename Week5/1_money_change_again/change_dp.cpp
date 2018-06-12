#include <iostream>
#include <vector>
/* https://www.dyclassroom.com/dynamic-programming/coin-changing-problem  IMPLEMENTATION */
using std::vector;

vector<int> Coins(3);

int get_change(int m)
{
	vector<int> MinNumCoins(m+1);
	int NumbCoins = 0;
	MinNumCoins[0]=0;
	for(int i = 1; i <= m ; i++)
	{
		MinNumCoins[i]=333;
		for(int j = 0; j<Coins.size() ;j++)
		{
			if(i >= Coins[j])
			{
				NumbCoins = MinNumCoins[i-Coins[j]] + 1;
				if(NumbCoins < MinNumCoins[i])
				{
					MinNumCoins[i] = NumbCoins;
				}
			}
		}

	}
	return MinNumCoins[m];
}

int main() {
	int m;
	std::cin >> m;

	Coins[0]=1;
	Coins[1]=3;
	Coins[2]=4;

	std::cout << get_change(m) << '\n';
}
