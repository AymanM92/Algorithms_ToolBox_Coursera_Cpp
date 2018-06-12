#include <iostream>
#include <vector>

using std::vector;


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
    int Asize = a.size();
	int Bsize = b.size();
	int Csize = c.size();
	int D[Asize+1][Bsize+1][Csize+1];

	for(int i=0; i<=Asize; i++) {
		for(int j=0; j<=Bsize; j++) {
			for(int k=0; k<=Csize; k++) {
				if(i == 0 || j == 0 || k == 0)
					D[i][j][k] = 0;
				else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
					D[i][j][k] = D[i-1][j-1][k-1] + 1;
				else
					D[i][j][k] = std::max(std::max(std::max(std::max(std::max(D[i-1][j][k], D[i][j-1][k]), D[i][j][k-1]), D[i-1][j-1][k]), D[i-1][j][k-1]), D[i][j-1][k-1]);
			}
		}
	}
    return D[Asize][Bsize][Csize];
}

//int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
//  //write your code here
//  return std::Bsizein(std::min(a.size(), b.size()), c.size());
//}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
