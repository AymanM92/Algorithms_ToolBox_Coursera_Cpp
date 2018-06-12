#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W,   const vector<int> &wt   )
{
    int i, w;
    vector<vector<int> > D( wt.size()+1   , vector<int>(W+1)   );

    for (i = 0; i <= wt.size(); i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                D[i][w] = 0;
            else if (wt[i - 1] <= w)
                D[i][w] = std::max(   wt[i - 1] + D[i - 1][w - wt[i - 1]]    ,    D[i - 1][w]   );
            else
                D[i][w] = D[i - 1][w];
        }
    }

    return K[wt.size()][W];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
