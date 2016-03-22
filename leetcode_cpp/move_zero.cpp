//https://leetcode.com/problems/move-zeroes/

void moveZeroes(int* nums, int numsSize) {
  int zeroFlag = -1;
  int numFlag = -1;
  int tmpZeroFlag;
  int tmpNumFlag;
  while(numFlag < numsSize - 1) {
    //find
    tmpZeroFlag = zeroFlag;
    for(int i = tmpZeroFlag + 1; i < numsSize; i++){
      if (nums[i] == 0){
	zeroFlag = i;
	break;
      }
    }
    if (zeroFlag == tmpZeroFlag) {
      break;
    }
    tmpNumFlag = numFlag;
    for(int i = zeroFlag + 1; i < numsSize; i++){
      if (nums[i] != 0){
	numFlag = i;
	break;
      }
    }
    if (numFlag == tmpNumFlag) {
      return;
    }
    if (numFlag < zeroFlag){
      return;
    }
    nums[zeroFlag] = nums[numFlag];
    nums[numFlag] = 0;
  }
}
