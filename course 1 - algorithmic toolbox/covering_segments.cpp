#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool sortByRightEdge(const Segment &a, const Segment &b)
{
	return a.end <= b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::sort(segments.begin(), segments.end(), sortByRightEdge);

  for (size_t i = 0; i < segments.size(); ++i) {
	  bool foundPointInSegment = false;
	  for (size_t j = 0; j < points.size(); ++j) {
		  if (  ( segments[i].start <= points[j] )
			 && ( points[j] <= segments[i].end   )
			  )
		  {
			  foundPointInSegment = true;
		  }
	  }

	  if (!foundPointInSegment) {
		  points.push_back(segments[i].end);
	  }
  }
  return points;
}

int main() {
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
