// https://leetcode.com/problems/meeting-rooms/

/*
  Given an array of meeting time intervals consisting of start and 
  end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person 
  could attend all meetings.

  For example,
  Given [[0, 30],[5, 10],[15, 20]],
  return false.
*/

#include <vector>
#include <algorithm>

using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(Interval const& a, Interval const& b) {
  return a.start < b.start;
}

bool overlaps(Interval const& a, Interval const& b) {
  return a.start < b.end && b.start < a.end;
}

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    for (int i = 1; i < (int)intervals.size(); ++i) {
      if (overlaps(intervals[i - 1], intervals[i])) return false;
    }
    return true;
  }
};
