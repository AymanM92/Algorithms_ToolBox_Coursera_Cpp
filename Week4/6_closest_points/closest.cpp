#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h>
#include <stdlib.h>

using std::vector;
using std::string;
using std::pair;
using std::min;
using namespace std;

//// A divide and conquer program in C++ to find the smallest distance from a
//// given set of points.
//
//
//// A structure to represent a Point in 2D plane
//struct Point
//{
//	int x, y;
//};
//
//
///* Following two functions are needed for library function qsort().
//Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
//
//// Needed to sort array of points according to X coordinate
//int compareX(const void* a, const void* b)
//{
//	Point *p1 = (Point *)a, *p2 = (Point *)b;
//	return (p1->x - p2->x);
//}
//// Needed to sort array of points according to Y coordinate
//int compareY(const void* a, const void* b)
//{
//	Point *p1 = (Point *)a, *p2 = (Point *)b;
//	return (p1->y - p2->y);
//}
//
//// A utility function to find the distance between two points
//float dist(Point p1, Point p2)
//{
//	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
//				(p1.y - p2.y)*(p1.y - p2.y)
//			);
//}
//
//// A Brute Force method to return the smallest distance between two points
//// in P[] of size n
//float bruteForce(Point P[], int n)
//{
//	float min = FLT_MAX;
//	for (int i = 0; i < n; ++i)
//		for (int j = i+1; j < n; ++j)
//			if (dist(P[i], P[j]) < min)
//				min = dist(P[i], P[j]);
//	return min;
//}
//
//// A utility function to find minimum of two float values
//float min(float x, float y)
//{
//	return (x < y)? x : y;
//}
//
//
//// A utility function to find the distance beween the closest points of
//// strip of given size. All points in strip[] are sorted accordint to
//// y coordinate. They all have an upper bound on minimum distance as d.
//// Note that this method seems to be a O(n^2) method, but it's a O(n)
//// method as the inner loop runs at most 6 times
//float stripClosest(Point strip[], int size, float d)
//{
//	float min = d; // Initialize the minimum distance as d
//
//	// Pick all points one by one and try the next points till the difference
//	// between y coordinates is smaller than d.
//	// This is a proven fact that this loop runs at most 6 times
//	for (int i = 0; i < size; ++i)
//		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
//			if (dist(strip[i],strip[j]) < min)
//				min = dist(strip[i], strip[j]);
//
//	return min;
//}
//
//// A recursive function to find the smallest distance. The array Px contains
//// all points sorted according to x coordinates and Py contains all points
//// sorted according to y coordinates
//float closestUtil(Point Px[], Point Py[], int n)
//{
//	// If there are 2 or 3 points, then use brute force
//	if (n <= 3)
//		return bruteForce(Px, n);
//
//	// Find the middle point
//	int mid = n/2;
//	Point midPoint = Px[mid];
//
//
//	// Divide points in y sorted array around the vertical line.
//	// Assumption: All x coordinates are distinct.
//	Point Pyl[mid+1]; // y sorted points on left of vertical line
//	Point Pyr[n-mid-1]; // y sorted points on right of vertical line
//	int li = 0, ri = 0; // indexes of left and right subarrays
//	for (int i = 0; i < n; i++)
//	{
//	if (Py[i].x <= midPoint.x)
//		Pyl[li++] = Py[i];
//	else
//		Pyr[ri++] = Py[i];
//	}
//
//	// Consider the vertical line passing through the middle point
//	// calculate the smallest distance dl on left of middle point and
//	// dr on right side
//	float dl = closestUtil(Px, Pyl, mid);
//	float dr = closestUtil(Px + mid, Pyr, n-mid);
//
//	// Find the smaller of two distances
//	float d = min(dl, dr);
//
//	// Build an array strip[] that contains points close (closer than d)
//	// to the line passing through the middle point
//	Point strip[n];
//	int j = 0;
//	for (int i = 0; i < n; i++)
//		if (abs(Py[i].x - midPoint.x) < d)
//			strip[j] = Py[i], j++;
//
//	// Find the closest points in strip. Return the minimum of d and closest
//	// distance is strip[]
//	return min(d, stripClosest(strip, j, d) );
//}
//
//// The main functin that finds the smallest distance
//// This method mainly uses closestUtil()
//float minimal_distance(vector<Point> P, size_t n)
//{
//	Point Px[n];
//	Point Py[n];
//	for (int i = 0; i < n; i++)
//	{
//		Px[i] = P[i];
//		Py[i] = P[i];
//	}
//
//	qsort(Px, n, sizeof(Point), compareX);
//	qsort(Py, n, sizeof(Point), compareY);
//
//	// Use recursive function closestUtil() to find the smallest distance
//	return closestUtil(Px, Py, n);
//}
//
///*
//double minimal_distance(vector<int> x, vector<int> y) {
//  //write your code here
//  return 0.;
//}
//*/
//

struct Point {
    double x, y;
};

Point result1, result2;
double bestDistance;

double Distance(Point a, Point b)  {
    double X = a.x - b.x, Y = a.y - b.y;
    return sqrt(X*X + Y*Y);
}

// comparison first done by y coordinate, then by x coordinate
bool lessT(Point a, Point b) {
    if(a.y < b.y) return true;
    if(a.y > b.y) return false;
    return a.x < b.x;
}

void merge(Point* a, Point* aux, int lo, int mid, int hi)   {
    int i, j, k;
    for(k = lo; k <= hi; k++)
        aux[k] = a[k];

    i = lo; j = mid + 1; k = lo;
    while(i <= mid && j <= hi)
        a[k++] = lessT(aux[i], aux[j]) ? aux[i++] : aux[j++];

    // Copy the rest of the left side of the array into the target array
    while(i <= mid)
        a[k++] = aux[i++];
}

double closestPair(Point* pointsByX, Point* pointsByY, Point* aux, int lo, int hi)    {
    if(hi <= lo)
        return numeric_limits<double>::infinity();

    int mid = lo + (hi - lo)/2;
    double delta = closestPair(pointsByX, pointsByY, aux, lo, mid);
    double dist = closestPair(pointsByX, pointsByY, aux, mid+1, hi);
    if(dist < delta)
        delta = dist;

    merge(pointsByY, aux, lo, mid, hi);

    int M = 0, i, j;
    for(i = lo; i <= hi; i++)
        if(abs(pointsByY[i].x - pointsByX[mid].x) < delta)
            aux[M++] = pointsByY[i];

    //double distance, t;
    for(i = 0; i < M; i++)  {
        for(j = i+1; j < M && (aux[j].y - aux[i].y < delta); j++) {
            distance = Distance(aux[i], aux[j]);
            if(distance < delta)    {
                delta = distance;
                if(delta < bestDistance) {
                    bestDistance = delta;
                    result1 = aux[i];
                    result2 = aux[j];
                }
            }
        }
    }
    return delta;
}

bool X_ORDER(Point a, Point b)  {
    return a.x < b.x;
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<Point> Points(n);
  vector<Point> pointsByY(n);
  vector<Point> aux(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> Points[i].x >> Points[i].y;
  }

  sort(Points.begin(), Points.end(), X_ORDER);

  for(size_t i=0; i<pointsByY.size(); i++)
      pointsByY[i] = Points[i];
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << closestPair(Points,pointsByY, Points.size(),aux, 0, Points.size()-1) << "\n";
}
//int main()  {
//    int N, i;
//    Point *points, *pointsByY, *aux;
//
//    //freopen("input.txt", "r", stdin);
//
//    scanf("%d", &N);    //Enter the number of points in the plane
//    points = new Point[N];
//    for(i=0; i<N; i++)  // Enter N points (x, y)
//        scanf("%lf %lf", &points[i].x, &points[i].y);
//
//    if(N <= 1) return 0;
//
//    sort(points, points + N, X_ORDER);
//    pointsByY = new Point[N];
//    for(i=0; i<N; i++)
//        pointsByY[i] = points[i];
//    aux = new Point[N];
//
//    bestDistance = numeric_limits<double>::infinity();
//    closestPair(points, pointsByY, aux, 0, N-1);
//
//    // print the closest pair of points and their euclidean distance
//    printf("%lf %lf\n", result1.x, result1.y);
//    printf("%lf %lf\n", result2.x, result2.y);
//    printf("%lf\n", bestDistance);
//
//    return 0;
//}
