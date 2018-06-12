#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>

using std::vector;
using std::string;

int max(int a, int b);

int lcs2L(vector<int> &a, vector<int> &b) {
    int Asize = a.size();
	int Bsize = b.size();
	int D[Asize+1][Bsize+1];

	for(int i=0; i<=Asize; i++) {
		for(int j=0; j<=Bsize; j++) {
				if(i == 0 || j == 0)
					D[i][j] = 0;
				else if(a[i-1] == b[j-1])
					D[i][j] = D[i-1][j-1] + 1;
				else
					D[i][j] = std::max(D[i-1][j],D[i][j-1]);
		}
	}
    return D[Asize][Bsize];
}
//
//int lcs2(vector<int> arr1 , vector<int> arr2)
//{
//	int m = arr1.size();
//	int n = arr2.size();
//	int result =0;
//
//	/*std::cout <<"Array1 size = "<<arr1.size()<<" m = "<<m<<std::endl;
//	std::cout <<"Array2 size = "<<arr2.size()<<" n = "<<n<<std::endl;*/
//	int tableArr1[m];
//	int tableArr2[n];
//
///*	std::cout <<"Array1 Table = ";*/
//	for (int j=0; j<m; j++)
//	{
//		tableArr1[j] = 0;
///*		std::cout <<tableArr1[j]<<" ";*/
//	}
///*	std::cout <<std::endl;
//	std::cout <<"Array2 Table = ";*/
//	for(int i=0; i<n; i++)
//	{
//		tableArr2[i] = 0;
///*		std::cout <<tableArr2[i]<<" ";*/
//	}
//	//std::cout <<std::endl;
//	// Traverse all elements of arr1[]
//	for (int i=0; i<n; i++)
//	{
//		// Initialize current length of LCIS
//		//int current = 0;
//
//		// For each element of arr1[], trvarse all
//		// elements of arr2[].
//		for (int j=0; j<m; j++)
//		{
//			// If both the array have same elements.
//			// Note that we don't break the loop here.
//			if (arr1[j] == arr2[i])
//			{//  if (current + 1 > table[j])
//				//    table[j] = current + 1;
//				tableArr1[j] = 1;
//				tableArr2[i] = 1;
//			}
//			/* Now seek for previous smaller common
//               element for current element of arr1 */
//			//            if (arr1[i] > arr2[j])
//			//                if (tableJ[j] > current)
//			//                    current = tableJ[j];
//		}
//	}
//
//	// The maximum value in table[] is out result
//	int ArrHit1 = 0;
//	int ArrHit2 = 0;
//
///*	std::cout <<"Table of Array1 = ";*/
//
//	for (int i=0; i<m; i++)
//	{
//		//        if (table[i] > result)
//		//           result = table[i];
//		if(1==tableArr1[i])
//		{
//			ArrHit1++;
//
//		}
//		/*std::cout << tableArr1[i]<<" ";*/
//	}
//	/*std::cout << std::endl;
//	std::cout <<"Table of Array2 = ";*/
//	for (int i=0; i<n; i++)
//	{
//		//        if (table[i] > result)
//		//           result = table[i];
//		if(1==tableArr2[i])
//		{
//			ArrHit2++;
//		}
//		//std::cout << tableArr2[i]<<" ";
//	}
//	//std::cout << std::endl;
//	if((ArrHit1 == ArrHit2)&&(ArrHit1 > 1))
//	{
//		result = ArrHit1;
//	}
//	else
//	{
//		result = 0;
//	}
//	return result;
//}
////int Minimum(int x,int y,int z)
////{
////	int Mini,MiniMini;
////
////	Mini = std::min(x,y);
////	MiniMini = std::min(Mini,z);
////
////    return MiniMini;
////}
////
////int edit_distance(const string &str1, const string &str2)
////{
////	vector<vector<int> > D( str1.length()+1   , vector<int>(str2.length()+1)   );
////	int Insertion,Deletion,Match,Mismatch;
////
////	for(int i=0;i<=str1.length();i++)
////	{
////
////		for(int j=0;j<=str2.length();j++)
////		{
////			if(0==j)
////			{
////				D[i][0]=i;
////			}
////			else if(0==i)
////			{
////				D[0][j]=j;
////			}
////			else
////			{
////				Insertion = D[i][j-1]+1;
////				Deletion = D[i-1][j]+1;
////				Match = D[i-1][j-1];
////				Mismatch =D[i-1][j-1]+1;
////				//std::cout<<"Insertion="<<Insertion<<" Deletion="<<Deletion<<" Match="<<Match<<" Mismatch="<<Mismatch<<std::endl;
////				//std::cout<<"String_1["<<i<<"] = "<<str1[i]<<" String_2["<<j<<"] = "<<str2[j]<<std::endl;
////				if(str1[i-1]==str2[j-1])
////				{
////					D[i][j] = Minimum(Insertion,Deletion,Match);
////					//std::cout<<"Minimum(Match) = D["<<i<<"]["<<j<<"] = "<<D[i][j]<<std::endl;
////				}
////				else
////				{
////					D[i][j] = Minimum(Insertion,Deletion,Mismatch);
////					//::cout<<"Minimum(Mismatch) = D["<<i<<"]["<<j<<"] = "<<D[i][j]<<std::endl;
////				}
////				//std::cout<<std::endl;
////			}
////		}
////	}
////	//std::cout<<"Return -> D["<<str1.length()<<"]["<<str2.length()<<"] = "<<D[str1.length()][str2.length()]<<std::endl;
////	return D[str1.length()][str2.length()];
////}
////
////int lcs2(vector<int> &a, vector<int> &b)
////{
////  //write your code here
////	int TotalNumCommon = a.size() + b.size();
////	string  strA="";
////	string  strB="";
////
////	for(int i=0 ; i< a.size() ; i++)
////	{
////		strA+=std::to_string(a[i]);
////	}
////	for(int j=0 ; j< b.size() ; j++)
////	{
////		strB+=std::to_string(b[j]);
////	}
////
////	int Distance = edit_distance(strA,strB);
////
////	/* Transfering the a and b to strings*/
////
////  return ((TotalNumCommon-(Distance)));//std::min(std::min(a.size(), b.size()), c.size());
////}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2L(a, b) << std::endl;


}
