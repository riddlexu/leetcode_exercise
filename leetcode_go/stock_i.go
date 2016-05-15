func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	min := prices[0]
	maxSum := 0
	for i := 1; i < len(prices); i++ {
		if prices[i]-min > maxSum {
			maxSum = prices[i] - min
		} else if prices[i] < min {
			min = prices[i]
		}
	}
	return maxSum
}
