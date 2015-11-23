class Solution {
public:
  string intToRoman(int num) {
    string roman[] = {"M", "CM","D", "CD", "C", "XC", "L","XL", "X","IX", "V", "IV", "I"};
    int    number[] ={1000,900, 500, 400,  100,  90,  50,  40,   10, 9,    5,    4,   1};
    string ans = "";
    int flag = 0;
    int i;
    while(num > 0) {
      for (i = flag; i < 13; i++) {
	if (num >= number[i]) {
	  num = num - number[i];
	  ans = ans.append(roman[i]);
	  flag = i;
	  break;
	}
      }
    }
    return ans;     
  }
};
