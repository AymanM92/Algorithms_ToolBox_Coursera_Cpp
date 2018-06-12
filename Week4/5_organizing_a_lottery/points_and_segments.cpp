#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

struct Info{
    int pos;
    char type;
    int pointIndex;
};

bool myCompare(Info i1, Info i2){
    // special case: when segment and point have same pos value
    if(i1.pos == i2.pos){
        // must keep [L, P, R] order
        if((i1.type == 'L' && i2.type == 'P' ) || (i1.type == 'P' && i2.type == 'L'))
            return i1.type < i2.type;
        if((i1.type == 'P' && i2.type == 'R' ) || (i1.type == 'R' && i2.type == 'P'))
            return i1.type < i2.type;
        if((i1.type == 'L' && i2.type == 'R' ) || (i1.type == 'R' && i2.type == 'L'))
            return i1.type < i2.type;
    }
    return i1.pos < i2.pos;
}

vector<int> fast_count_segments(vector<Info> info, int pointNumber)
{
    vector<int> cnt(pointNumber);
    //write your code here
    int left = 0;
    for(size_t i = 0; i < info.size(); i++){
        //cout << info[i].pos << ", " << info[i].type << endl;
        if(info[i].type == 'P'){
            cnt[info[i].pointIndex] = left;
        }
        if(info[i].type == 'L'){
            left++;
        }
        if(info[i].type == 'R'){
            left--;
        }
    }
    return cnt;
}
//struct Segment {
//  int x, y;
//};

//bool SortByX (Segment i,Segment j) { return (i.x<j.x); }
//bool SortByY (Segment i,Segment j) { return (i.y<j.y); }
//
//int StartSearch(vector<Segment> segments, int left, int right, int point) {
//        int pos = -1;
//        while (left <= right)
//        {
//            if (left == right)
//            {
//                Segment p = segments[left];
//                if (p.x <= point)
//                {
//                    pos = left;
//                }
//                break;
//            }
//            int mid = left + (right - left) / 2;
//            Segment p = segments[mid];
//            if (p.x <= point)
//            {
//                pos = mid;
//                left = mid + 1;
//            }
//            else if (p.x > point)
//            {
//                right = mid;
//            }
//        }
//        return pos;
//}
//
//int EndSearch(vector<Segment> segments, int left, int right, int point)
//{
//        if (segments.empty()) return -1;
//        if (left == right)
//        {
//            return segments[left].y >= point ? left : -1;
//        }
//        int mid = left + (right - left) / 2;
//        Segment p = segments[mid];
//        if (p.y >= point)
//        {
//            return EndSearch(segments, left, mid, point);
//        }
//        else
//        {
//            return EndSearch(segments, mid + 1, right, point);
//        }
//}
//
//vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
//{
//    vector<int> cnt(points.size());
//    vector<Segment> segments(starts.size());
//
//    for (size_t i = 0; i < segments.size(); ++i)
//    {
//        segments[i].x = starts[i];
//        segments[i].y = ends[i];
//    }
//
//    sort(segments.begin(), segments.end(), SortByX);
//
//    for (size_t i = 0; i < points.size(); i++)
//    {
//        int pos = StartSearch(segments, 0, segments.size() - 1, points[i]);
//        if (pos != -1) {
//            vector<Segment> head(pos+1);
//            for(int i = 0; i < pos+1; ++i) {
//                head[i].x = segments[i].x;
//                head[i].y = segments[i].y;
//            }
//            sort(segments.begin(), segments.end(), SortByY);
//            pos = EndSearch(head, 0, head.size() - 1, points[i]);
//            int c = pos != -1 ? head.size() - pos : 0;
//            cnt[i] = c;
//        }
//        else cnt[i] = 0;
//    }
//    return cnt;
//}
//
//vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//	vector<int> cnt(points.size());
//	for (size_t i = 0; i < points.size(); i++) {
//		for (size_t j = 0; j < starts.size(); j++) {
//			cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//		}
//	}
//	return cnt;
//}
int main(){
    // n = number of segments, m = number of points
    int n, m;
    cin >> n >> m;
    vector<Info> info(n*2+m);  // store the position information of each segment and point in info structure
    // store segments
    int j = 0;
    for (size_t i = 0; i < n; i++){
        cin >> info[j].pos >> info[j+1].pos;
        info[j].type = 'L'; info[j+1].type = 'R';
        info[j].pointIndex = -1; info[j+1].pointIndex = -1;
        j = j + 2;

    }
    // store points
    for(size_t i = 0; i < m; i++){
        cin >> info[j].pos;
        info[j].type = 'P';
        info[j].pointIndex = i;
        j++;

    }
    // sort the info by pos value
    sort(info.begin(), info.end(), myCompare);
    //use fast_count_segments
    vector<int> cnt = fast_count_segments(info, m);
    for (size_t i = 0; i < cnt.size(); i++){
        cout << cnt[i] << ' ';
    }
}
/*
int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
	}
	//use fast_count_segments
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) {
		std::cout << cnt[i] << ' ';
	}
}
*/
