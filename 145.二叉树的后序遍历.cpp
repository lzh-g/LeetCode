/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // 修改前序遍历再翻转
        vector<int> res;
        stack<TreeNode *> m_s;

        if (root == NULL)
        {
            return res;
        }
        m_s.push(root);
        while (!m_s.empty())
        {
            TreeNode *node = m_s.top();
            m_s.pop();
            res.push_back(node->val); // 中
            if (node->left)
            {
                m_s.push(node->left);
            }
            if (node->right)
            {
                m_s.push(node->right);
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end
