/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */
#include <iostream>
#include <queue>
#include <stack>

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
    int pre;
    void traversal(TreeNode *cur)
    {
        // if (cur == NULL)
        // {
        //     return;
        // }
        // traversal(cur->right); // 右
        // cur->val += pre;       // 中
        // pre = cur->val;
        // traversal(cur->left); // 左

        // 迭代法
        stack<TreeNode *> st;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->right; // 右
            }
            else
            {
                cur = st.top(); // 中
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left; // 左
            }
        }
    }
    TreeNode *convertBST(TreeNode *root)
    {
        // 中序遍历，左中右
        // 逆序中序遍历，右中左
        pre = 0;
        traversal(root);
        return root;
    }
};
// @lc code=end
