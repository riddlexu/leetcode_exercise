func lengthOfLongestSubstring(s string) int {
	max := 0
	for i := 0; i < len(s); i++ {
		location := make(map[byte]int)
		for j := i; j < len(s); j++ {
		    loc, ok := location[s[j]]
		    if ok {
		        i = loc
		        break
		    }
		    if j - i + 1 > max {
		        max = j - i + 1
		    }
		    location[s[j]] = j     
		}
	}
	return max
}