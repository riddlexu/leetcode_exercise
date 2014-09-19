//https://oj.leetcode.com/problems/max-points-on-a-line/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
 public:
  int maxPoints(vector<Point> &points) {
    std::unordered_map<double,int> slope;
    int ans = 0;
    for (int i = 0; i < points.size(); i++){
      slope.clear();
      int samepoint = 1;
      int samex = 0;
      int sameline = 0;
      for (int j = i+1; j < points.size(); j++){
        if (points[i].x == points[j].x && points[i].y == points[j].y){
          samepoint++;

        }
        else if(points[i].x == points[j].x){
          samex++;                   
        }
        else{
          double tmp = 1.0*(points[i].y - points[j].y)/(points[i].x - points[j].x);
          if (slope.count(tmp) == 0){
            slope.insert(unordered_map<double,int>::value_type(tmp,1));
          }
          else {
            slope[tmp]++;
          }
          if (slope[tmp] > sameline){
            sameline = slope[tmp];
          }

        }
      }
      if (samepoint + max(samex,sameline) > ans){
        ans = samepoint + max(samex,sameline);
      }
    }
    return ans;
  }
};
