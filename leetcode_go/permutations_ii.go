func permuteUnique(nums []int) [][]int {
    for i :=0; i < len(nums) -1; i++{
        for j := 0; j < len(nums) - 1 - i; j++ {
            if nums[j] > nums[j + 1] {
                tmp := nums[j]
                nums[j] = nums[j + 1]
                nums[j + 1] = tmp
            }
        }
    }    
    return permuteUniqueSorted(nums)
}

func permuteUniqueSorted(nums []int) [][]int {
    result := make([][]int, 0)
    if len(nums) == 0 {
        return result
    }
    if len(nums) == 1 {
        result = append(result, nums)
        return result
    }
    for i := 0;i < len(nums); i++{
        if i > 0 && nums[i] == nums[0] {
            continue
        }
        tmp := nums[0]
        nums[0] = nums[i]
        nums[i] = tmp
	newNums := make([]int, 0)
	//because not swap back. So must not use reference    
        for j := 0; j < len(nums) - 1; j++{
            newNums = append(newNums, nums[j + 1])
        }
        leftResult := permuteUniqueSorted(newNums)
        for _, res := range leftResult{
            result = append(result, append([]int{nums[0]},res...))
        }
	//not swap back. It's the point    
    }
    return result
}
