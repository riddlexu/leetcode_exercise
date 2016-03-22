//https://oj.leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() < 2){
      return intervals;
    }
    std::sort(intervals.begin(), intervals.end(), mycompare);
    int index = 1;
    while(index < intervals.size()){
      if (intervals[index-1].end >= intervals[index].start){
        intervals[index-1].end = std::max(intervals[index-1].end, intervals[index].end);
        intervals.erase(intervals.begin() + index);
      }
      else{
        index++;
      }
    }
    return intervals;
  }
  static bool mycompare(Interval x, Interval y){
    return x.start < y.start;
  }
};
