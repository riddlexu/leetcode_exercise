/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * 
}
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if (l1 == nil) {
		return l2		
	}
	if (l2 == nil) {
		return l1
	}
	var ans *ListNode
	index := ListNode{Val: (l1.Val + l2.Val) % 10}
	andOne := (l1.Val + l2.Val) / 10
	ans = &index
	p := &index
	for ((l1.Next != nil) && (l2.Next != nil)) {
		l1 = l1.Next
		l2 = l2.Next
		node := ListNode{Val: (l1.Val + l2.Val + andOne) % 10}
		andOne = (l1.Val + l2.Val + andOne) / 10
		p.Next = &node
		p = p.Next
	}
	if (l2.Next != nil) {
		l1 = l2
	}
	for (l1.Next != nil) {
		l1 = l1.Next
		node := ListNode{Val: (l1.Val + andOne) % 10}
		andOne = (l1.Val + andOne) / 10
		p.Next = &node
		p = p.Next		
	}
	if (andOne > 0) {
		node := ListNode{Val: andOne}
		p.Next = &node
	}
	return ans
}
