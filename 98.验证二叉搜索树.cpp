/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // TreeNode *pre = NULL;
    bool isValidBST(TreeNode *root)
    {
        // // 中序遍历，pre存储中序遍历当前节点的前一个节点
        // if (root == NULL)
        // {
        //     return true;
        // }
        // bool left = isValidBST(root->left);       // 左
        // if (pre != NULL && pre->val >= root->val) // 中
        // {
        //     return false;
        // }
        // pre = root;
        // bool right = isValidBST(root->right); // 右

        // return left && right;

        // 迭代法中序遍历
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = st.top(); // 中
                st.pop();
                // 栈中前一个访问的节点，从根节点往下访问，若根<左，则错误
                if (pre != NULL && cur->val <= pre->val)
                {
                    return false;
                }
                pre = cur;
                cur = cur->right; // 右
            }
        }

        return true;
    }
};
// @lc code=end
