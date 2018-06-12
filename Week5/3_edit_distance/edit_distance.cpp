#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

int Minimum(int x,int y,int z)
{
	int Mini,MiniMini;

	Mini = std::min(x,y);
	MiniMini = std::min(Mini,z);

    return MiniMini;
}

int edit_distance(const string &str1, const string &str2)
{
	vector<vector<int> > D( str1.length()+1   , vector<int>(str2.length()+1)   );
	int Insertion,Deletion,Match,Mismatch;

	for(int i=0;i<=str1.length();i++)
	{

		for(int j=0;j<=str2.length();j++)
		{
			if(0==j)
			{
				D[i][0]=i;
			}
			else if(0==i)
			{
				D[0][j]=j;
			}
			else
			{
				Insertion = D[i][j-1]+1;
				Deletion = D[i-1][j]+1;
				Match = D[i-1][j-1];
				Mismatch =D[i-1][j-1]+1;
				//std::cout<<"Insertion="<<Insertion<<" Deletion="<<Deletion<<" Match="<<Match<<" Mismatch="<<Mismatch<<std::endl;
				//std::cout<<"String_1["<<i<<"] = "<<str1[i]<<" String_2["<<j<<"] = "<<str2[j]<<std::endl;
				if(str1[i-1]==str2[j-1])
				{
					D[i][j] = Minimum(Insertion,Deletion,Match);
					//std::cout<<"Minimum(Match) = D["<<i<<"]["<<j<<"] = "<<D[i][j]<<std::endl;
				}
				else
				{
					D[i][j] = Minimum(Insertion,Deletion,Mismatch);
					//::cout<<"Minimum(Mismatch) = D["<<i<<"]["<<j<<"] = "<<D[i][j]<<std::endl;
				}
				//std::cout<<std::endl;
			}
		}
	}
	//std::cout<<"Return -> D["<<str1.length()<<"]["<<str2.length()<<"] = "<<D[str1.length()][str2.length()]<<std::endl;
	return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
