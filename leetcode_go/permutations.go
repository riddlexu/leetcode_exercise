func permute(nums []int) [][]int {
    data := make([][]int, 0)
    if len(nums) == 0 {
        return data
    }
    if len(nums) == 1 {
        data = append(data,nums)
        return data
    }
    head := nums[0]
    for i := 0; i < len(nums); i++ {
        nums[0] = nums[i]
        nums[i] = head
        results := permute(nums[1:])
        for _, result := range results {
            data = append(data,append([]int{nums[0]}, result...))
        }
        nums[i] = nums[0]
        nums[0] = head
    }
    return data
}
