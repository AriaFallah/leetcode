// https://leetcode.com/problems/meeting-rooms-ii/

/*
  Given an array of meeting time intervals consisting of start 
  and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum 
  number of conference rooms required.

  For example,
  Given [[0, 30],[5, 10],[15, 20]],
  return 2.
*/

#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::vector;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> meetings;
    for (auto i : intervals) {
      meetings[i.start] += 1;
      meetings[i.end] -= 1;
    }
    int rooms = 0, maxrooms = 0;
    for (auto meeting : meetings)
      maxrooms = std::max(maxrooms, rooms += meeting.second);
    return maxrooms;
  }
};
