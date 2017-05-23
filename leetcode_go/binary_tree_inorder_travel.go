/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    var left []int
    if root.Left != nil {
        left = inorderTraversal(root.Left)
    }
    ans := append(left, root.Val)
    var right []int
    if root.Right != nil {
        right = inorderTraversal(root.Right)
    }
    ans = append(left, right...)
    return ans
}
