#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using std::vector;
using namespace std;

bool subsetSum(vector<int> Str, int n, int SumA, int SumB, int SumC, auto &lookup)
{
    if (SumA == 0 && SumB == 0 && SumC == 0)
    {
        return true;
    }
    if (n < 0)
    {
        return false;
    }
    string key = to_string(SumA) + "|" + to_string(SumB) + "|" + to_string(SumC) +
                "|" + to_string(n);

    if (lookup.find(key) == lookup.end())
    {

        bool A = false;
        if ((SumA - Str[n]) >= 0)
            A = subsetSum(Str, n - 1, SumA - Str[n], SumB, SumC, lookup);


        bool B = false;
        if (!A && (SumB - Str[n] >= 0))
            B = subsetSum(Str, n - 1, SumA, SumB - Str[n], SumC, lookup);


        bool C = false;
        if ((!A && !B) && (SumC - Str[n] >= 0))
            C = subsetSum(Str, n - 1, SumA, SumB, SumC - Str[n], lookup);


        lookup[key] = A || B || C;
    }
    return lookup[key];
}

bool partition3(vector<int> S, int n)
{
    if (n < 3)
        return false;

    int sum =0;
    unordered_map<string, bool> lookup;

    for(size_t i =0;i<S.size();i++)
    {
    	sum = sum + S[i];
    }

    return !(sum % 3) && subsetSum(S, S.size() - 1, sum/3, sum/3, sum/3, lookup);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A,A.size()) << '\n';
}
