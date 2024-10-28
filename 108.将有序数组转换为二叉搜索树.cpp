/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *traversal(vector<int> &nums, int start, int end)
    {
        // 终止条件
        if (start > end)
        {
            return NULL;
        }
        if (start == end)
        {
            return new TreeNode(nums[start]);
        }
        int mid = (start + end) / 2;
        TreeNode *res = new TreeNode(nums[mid]);
        res->left = traversal(nums, start, mid - 1);
        res->right = traversal(nums, mid + 1, end);
        return res;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // 取数组中间值为根节点
        TreeNode *res = traversal(nums, 0, nums.size() - 1);
        return res;
    }
};
// @lc code=end
