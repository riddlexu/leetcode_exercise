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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> ans;
    if(intervals.size() == 0){
      ans.push_back(newInterval);
      return ans;
    }
    if(newInterval.start < intervals[0].start){
      ans.push_back(newInterval);
      for(int i = 0; i < intervals.size(); i++){
        if(ans.back().end >= intervals[i].start){
          ans.back().end = max(ans.back().end, intervals[i].end);
        }
        else{
          ans.push_back(intervals[i]);
        }
      }
      return ans;
    }
    int left = newInterval.start;
    int right = newInterval.end;
    bool hasadd = false;
    for(int i = 0; i < intervals.size(); i++){
      if(intervals[i].end < left){
        ans.push_back(intervals[i]);
      }
      else if(!hasadd){
        hasadd = true;
        if(intervals[i].start <= left){
          ans.push_back(intervals[i]);
          ans.back().end = max(ans.back().end,right);
        }
        else if(intervals[i].start > right){
          ans.push_back(newInterval);
          ans.push_back(intervals[i]);
        }
        else{
          ans.push_back(newInterval);
          ans.back().end = max(ans.back().end,intervals[i].end);
        }
      }
      else if(intervals[i].start > right){
        ans.push_back(intervals[i]);
      }
      else{
        ans.back().end = max(ans.back().end, intervals[i].end);
      }
    }
    if(!hasadd){
      ans.push_back(newInterval);
    }
    return ans;
  }
};
