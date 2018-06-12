#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using std::vector;
using std::swap;
/*
7
3 3 3 5 7 7 7
*/

/*
int partition2(vector<int> &a, int left, int right) {
  int x = a[left];
  int j = left;

  for (int i = left + 1; i <= right; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }

  swap(a[left], a[j]); // no put the pivot in it's sorted place
  return j;
}
*/
/*
 int x = a[l];
    int m1 = l;
    int i = l;
    int m2 = r;
    vector<int> m(2);
    while (i <= m2) {
        if (a[i] < x) {
            swap(a[m1], a[i]);
            m1++;
            i++;
        } else if (a[i] == x) {
            i++;
        } else {
            swap(a[i], a[m2]);
            m2 -= 1;
        }
        m[0] = m1;
        m[1] = m2;
    }
    return m;
 */
vector<int> quick_sort_partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    int p_l = l;
    int i = l;
    int p_e = r;
    vector<int> m(2);
    while (i <= p_e) {
        if (a[i] < x) {
            swap(a[p_l], a[i]);
            p_l++;
            i++;
        } else if (a[i] == x) {
            i++;
        } else {
            swap(a[i], a[p_e]);
            p_e -= 1;
        }
        m[0] = p_l;
        m[1] = p_e;
    }
    return m;
}
std::tuple<int, int> partition3(vector<int> &a, int left, int right) {
  int x = a[left];
  int m1=left ,m2 = right;
  //std::cout <<"Start Partition with Start = "<<left<<" and End = "<<right<<std::endl;
  for (int i = left + 1; i <= m2; i++)
  {
    if (a[i] < x)
    {
        swap(a[m1], a[i]);
        m1++;
//        for(int cnt=0;cnt<a.size();cnt++)
//        {
//      	  std::cout <<a[cnt]<<" ";
//        }
//        std::cout<<std::endl;
//      std::cout <<"a["<<i<<"] < "<<x<<std::endl;
//      m1++;
////      std::cout <<"Need to swap a["<<m1<<"] = "<<a[m1]<<" with a["<<i<<"] = "<<a[i]<<std::endl;
//      swap(a[m1] , a[i] );
//      m2++;
//      if(m2 != i)
//      {
//      swap(a[m1] , a[m2]);
//      }
//     std::cout <<"Now m1 = "<<m1<<" m2 = "<<m2<<std::endl;
//      for(int cnt=0;cnt<a.size();cnt++)
//      {
//    	  std::cout <<a[cnt]<<" ";
//      }
//      std::cout<<std::endl;
    }
    else if (a[i] == x)
    {
//        for(int cnt=0;cnt<a.size();cnt++)
//        {
//      	  std::cout <<a[cnt]<<" ";
//        }
//        std::cout<<std::endl;
//    	std::cout <<"a["<<i<<"] = "<<x<<std::endl;
//    	m2++;
//    	swap(a[i], a[m2]);
//    	std::cout <<"Now m1 = "<<m1<<" m2 = "<<m2<<std::endl;
//        for(int cnt=0;cnt<a.size();cnt++)
//        {
//      	  std::cout <<a[cnt]<<" ";
//        }
//        std::cout<<std::endl;
    }
    else
    {
        swap(a[i], a[m2]);
        m2--;
//        for(int cnt=0;cnt<a.size();cnt++)
//        {
//      	  std::cout <<a[cnt]<<" ";
//        }
//        std::cout<<std::endl;
//    	std::cout <<"a["<<i<<"] > "<<x<<std::endl;
//    	std::cout <<"Now m1 = "<<m1<<" m2 = "<<m2<<std::endl;
//        for(int cnt=0;cnt<a.size();cnt++)
//        {
//      	  std::cout <<a[cnt]<<" ";
//        }
//        std::cout<<std::endl;
    	//Don't Do anything actually The bigger
    }
  //  std::cout<<std::endl;
  }

  swap(a[left], a[m1]); // no put the pivot in it's sorted place
  return std::make_tuple(m1,m2);
}


void randomized_quick_sort(vector<int> &a, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  int PivotIndex = left + rand() % (right - left + 1); // calculated a random pivot index.

  //std::cout <<"The pivot here is "<<a[PivotIndex]<<std::endl;

  swap(a[left], a[PivotIndex]); //Swap it to the first place in the array to the left.

  int m1,m2 ;
 // std::tie(m1,m2) = partition3(a, left, right); //Then do the partitioning
  vector<int> m = quick_sort_partition3(a, left, right);
  randomized_quick_sort(a, left, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, right);
 // randomized_quick_sort(a, left, m1 - 1);
  //randomized_quick_sort(a, m2 + 1, right);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
