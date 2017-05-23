func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    if (len(nums1) + len(nums2)) % 2 == 1 {
        return float64(findKth(nums1, nums2, (len(nums1) + len(nums2)) / 2 + 1))
    } else {
        return float64(findKth(nums1, nums2, (len(nums1) + len(nums2)) / 2) + findKth(nums1, nums2, (len(nums1) + len(nums2)) / 2 + 1)) / 2.0
    }
}

func findKth(nums1 []int, nums2 []int, k int) int {
    if len(nums1) < len(nums2) {
        return findKth(nums2, nums1, k)
    }
    if len(nums2) == 0 {
        return nums1[k-1]
    } else if k == 1 {
        return minInt(nums1[0], nums2[0])
    } else if k == len(nums1) + len(nums2) {
        return maxInt(nums1[len(nums1) - 1], nums2[len(nums2) - 1])
    }
    bIndex := minInt(k / 2 - 1, len(nums2) - 1)
    aIndex := k - bIndex - 1 - 1
    if nums1[aIndex] < nums2[bIndex] {
        return findKth(nums1[aIndex+1:], nums2[:bIndex+1], k - aIndex - 1)
    } 
    return findKth(nums1[:aIndex+1], nums2[bIndex+1:],k-bIndex - 1)
}

func minInt(a, b int) int {
    if a < b {
        return a
    } 
    return b
}

func maxInt(a, b int) int {
    if a < b {
        return b
    } 
    return a
}
