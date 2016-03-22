func twoSum(nums []int, target int) []int {
	table := make(map[int]int)
	ans := make([]int, 2)
	for index, v := range nums {
		loc, ok := table[target - v]
		if ok {
			ans[0] = loc
			ans[1] = index
			return ans
			
		}
		table[v] = index
		
	}
	return ans
	
}
