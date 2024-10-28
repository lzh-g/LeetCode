/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include <iostream>
#include <vector>

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
    int rob(TreeNode *root)
    {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    // dp为长度为2的数组，0表示不偷，1表示偷
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == NULL)
        {
            return vector<int>{0, 0};
        }
        // 后序遍历
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷当前节点，则不偷左右节点
        int val1 = cur->val + left[0] + right[0];
        // 不偷当前节点，则左右节点可偷可不偷，取max
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return {val2, val1};
    }
};
// @lc code=end
