//#include <iostream>
//#include <numeric>
//#include <unordered_map>
//#include <vector>
////
//using std::vector;
//using namespace std;
//
//// Helper function for solving 3 partition problem
//// It return true if there exists three subsets with given sum
//
//bool subsetSum(vector<int> Str, int n, int a, int b, int c, auto &lookup)
//{
//    // return true if subset is found
//    if (a == 0 && b == 0 && c == 0)
//        return true;
//
//    // base case: no items left
//    if (n < 0)
//        return false;
//
//    // construct a unique map key from dynamic elements of the input
//    string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
//                "|" + to_string(n);
//
//    // if sub-problem is seen for the first time, solve it and
//    // store its result in a map
//    if (lookup.find(key) == lookup.end())
//    {
//        // Case 1. current item becomes part of first subset
//        bool A = false;
//        if ((a - Str[n]) >= 0)
//            A = subsetSum(Str, n - 1, a - Str[n], b, c, lookup);
//
//        // Case 2. current item becomes part of second subset
//        bool B = false;
//        if (!A && (b - Str[n] >= 0))
//            B = subsetSum(Str, n - 1, a, b - Str[n], c, lookup);
//
//        // Case 3. current item becomes part of third subset
//        bool C = false;
//        if ((!A && !B) && (c - Str[n] >= 0))
//            C = subsetSum(Str, n - 1, a, b, c - Str[n], lookup);
//
//        // return true if we get solution
//        lookup[key] = A || B || C;
//    }
//
//    // return the subproblem solution from the map
//    return lookup[key];
//}
//// Function for solving 3-partition problem. It return true if given
//// set A[0..n-1] can be divided into three subsets with equal sum
//bool partitioning(vector<int> S, int n)
//{
//    if (n < 3)
//        return false;
//
//    int sum =0;
//    // create a map to store solutions of subproblems
//    unordered_map<string, bool> lookup;
//
//    // get sum of all elements in the set
//    for(size_t i =0;i<S.size();i++)
//    {
//    	sum = sum + S[i];
//    }
//    //int sum = accumulate(S, S + n, 0);
//
//    // return true if sum is divisible by 3 and the set S can
//    // be divided into three subsets with equal sum
//    return !(sum % 3) && subsetSum(S, S.size() - 1, sum/3, sum/3, sum/3, lookup);
//}
//
//// main function for 3-partition problem
////int main()
////{
////    // Input: set of integers
////    int S[] = { 7, 3, 2, 1, 5, 4, 8 };
////
////    // number of items in S
////    int n = sizeof(S) / sizeof(S[0]);
////
////    if (partition(S, n))
////        cout << "Yes";
////    else
////        cout << "No";
////
////    return 0;
////}
