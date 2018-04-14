#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include "stdint.h"

using std::vector;

struct Segment {
	int start, end;
};

/*
5
1 3
2 5
3 6
7 8
8 9
 */


/* Function for the sort SDL to sort by the start address,  */
//bool compare(const Segment& lhs, const Segment& rhs) { return lhs.end < rhs.end; }

vector<int> optimal_points(vector<Segment> &segments)
		{
	vector<int> points;


	std::sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
		return a.end < b.end;
	});
	int point = segments[0].end;
	// std::cout << " Print the output of the search " << std::endl;

	//    for(int i=0 ; i< segments.size() ; i++)
	//    {
	//    std::cout << segments[i].start <<" "<< segments[i].end << std::endl;
	//    }

	//std::cout << std::endl;
	//std::cout << std::endl;

	for (size_t i = 1; i < segments.size(); ++i)
	{
		//std::cout <<"Segment of i="<<i<<" "<< segments[i].start <<" "<< segments[i].end << std::endl;
		//std::cout <<"point of comparison = "<<point<< std::endl;

		if (point < segments[i].start )
		{
			points.push_back(point);
			point = segments[i].end;
		}

		if( (i == (segments.size()-1)))
		{
			points.push_back(point);
		}
	}
	return points;
		}
///*
//Segment FindIntersection(Segment FirstSegment,Segment SecondSegment) /*First 4,7  Second 5,6  */
//{
//	//std::cout << "First Segment start = " << FirstSegment.start << " end = " << FirstSegment.end << std::endl;
//	//std::cout << "Second Segment start = " << SecondSegment.start << " end = " << SecondSegment.end << std::endl;
//	Segment Intersection;
//	if( (FirstSegment.start <= SecondSegment.start) && (FirstSegment.end >= SecondSegment.start) && (FirstSegment.end < SecondSegment.end) ) /* ///\\\  */
//	{
//		//std::cout << "This is and Intersection ---++||||" << std::endl;
//		Intersection.start = SecondSegment.start;
//		Intersection.end = FirstSegment.end;
//	}
//	else if( (FirstSegment.start <= SecondSegment.start) && (FirstSegment.end > SecondSegment.start) && (FirstSegment.end > SecondSegment.end) ) /*  ////XXXXXX////  */
//	{
//		//std::cout << "This is and Intersection ---++++----" << std::endl;
//		Intersection.start = SecondSegment.start;
//		Intersection.end = SecondSegment.end;
//	}
//	else
//	{
//		//std::cout << "This is no Intersection" << std::endl;
//		Intersection.start = 0;
//		Intersection.end = 0;
//	}
//	return Intersection;
//}
//
//vector<int> optimal_points(vector<Segment> &segments)
//						{
//	vector<int> points;
//	Segment Intersections , segments_intersections , LastIntersections;
//	uint16_t j = 1;
//	uint16_t i = 0;
//	uint16_t LastPush = 0;
//	bool LastWasIntersection , CurrentIsNotIntersection , LastTime = 0;
//	//write your code here
//	//std::cout << segments.size() << std::endl;
//	Intersections.start = 0;
//	Intersections.end = 0;
//	std::sort(segments.begin() ,segments.end() ,compare);
//
//	segments_intersections = segments[0];
////  std::cout <<"Sorted Array Printing:"<<std::endl;
////	for (size_t i = 0; i < segments.size(); ++i)
////	{
////		std::cout << segments[i].start  <<std::endl;
////	}
////	std::cout <<std::endl;
////	std::cout <<std::endl;
////	std::cout <<std::endl;
//
//	while( j < segments.size() )
//	{
//		//std::cout <<"Entered the While Loop "<<" i = " << i << " " << "j = " << j <<std::endl;
//		Intersections = FindIntersection(segments_intersections,segments[j]);
//		//std::cout <<" i = " << i << " " << "j = " << j <<" intersection in each while loop = " << Intersections.start << " " << Intersections.end <<std::endl;
//		//std::cout <<"The output of FindIntersection function is = "<< Intersections.start << " " << Intersections.end <<std::endl;
//
//		if( (0 == Intersections.start) && (0 == Intersections.end) )
//		{
//			LastWasIntersection = 0;
//			CurrentIsNotIntersection = 1;
//			LastIntersections = segments_intersections;
//			if(j == (segments.size()-1))
//			{
//				i = j-1;
//				LastTime = 1;
//			}
//			{
//				i = j;
//				j = i+1;
//			}
//			segments_intersections = segments[i];
//		}
//		else
//		{
//			if(j == (segments.size()-1))
//			{
//				LastTime = 1;
//			}
//			//Intersections = FindIntersection(Intersections,segments[j]);
//			segments_intersections = Intersections;
//			LastIntersections = segments_intersections;
//			LastWasIntersection = 1;
//			CurrentIsNotIntersection = 0;
//			j++;
//		}
//
//
//		if( (1 == LastWasIntersection) && (1 == CurrentIsNotIntersection) ) /*This time has no intersection and the one before has intersection*/
//		{
//			if( LastPush != LastIntersections.end)
//			{
//			points.push_back(LastIntersections.end);
//			LastPush = LastIntersections.end;
//			}
//			//std::cout << "This time has no intersection and the one before has intersection " << "LastWasIntersection = " << LastWasIntersection << " CurrentIsNotIntersection = " << CurrentIsNotIntersection <<" i = " << i << " " << "j = " << j <<" intersection in each while loop = " << LastIntersections.start << " " << LastIntersections.end <<std::endl;
//		}
//		else if( (0 == LastWasIntersection) && (1 == CurrentIsNotIntersection) ) /*The last one was not intersection and this also*/
//		{
//			if( LastPush != LastIntersections.end)
//			{
//			points.push_back(LastIntersections.end);
//			LastPush = LastIntersections.end;
//			}
//			//std::cout << "The last one was not intersection and this also " << "LastWasIntersection = " << LastWasIntersection << " CurrentIsNotIntersection = " << CurrentIsNotIntersection <<" i = " << i << " " << "j = " << j <<" intersection in each while loop = " << LastIntersections.start << " " << LastIntersections.end <<std::endl;
//		}
//		else if( (1 == LastWasIntersection) && (1 == LastTime) && (0 == CurrentIsNotIntersection) ) /*This is the last time has intersection and the one before has intersection*/
//		{
//			if( LastPush != LastIntersections.end)
//			{
//			points.push_back(LastIntersections.end);
//			LastPush = LastIntersections.end;
//			}
//			//std::cout << "This is the last time has intersection and the one before has intersection " << "LastWasIntersection = " << LastWasIntersection << " CurrentIsNotIntersection = " << CurrentIsNotIntersection <<" i = " << i << " " << "j = " << j <<" intersection in each while loop = " << LastIntersections.start << " " << LastIntersections.end <<std::endl;
//		}
//	}
//
//	//	for (size_t i = 0; i < segments.size(); ++i) {
//	//		points.push_back(segments[i].start);
//	//		points.push_back(segments[i].end);
//	//	}
//	return points;
//						}


int main()
{
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}


/*



 */
