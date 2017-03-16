func twoSum(numbers []int, target int) []int {
    record := make(map[int]int)
    ans := make([]int, 2)
    for i, n := range numbers {
        index1, ok := record[target - n]
        if ok {
            ans[0] = index1 + 1
            ans[1] = i + 1
            return ans
        }
        record[n] = i
    }
    return ans
}