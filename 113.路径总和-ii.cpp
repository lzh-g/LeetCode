/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include <iostream>
#include <stack>
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
private:
    vector<vector<int>> res;
    vector<int> path;

    void traversal(TreeNode *cur, int count)
    {
        if (!cur->left && !cur->right && count == 0)
        {
            res.push_back(path);
            return;
        }

        if (!cur->left && !cur->right)
        {
            return;
        }

        if (cur->left)
        {
            path.push_back(cur->left->val);
            traversal(cur->left, count - cur->left->val);
            path.pop_back();
        }
        if (cur->right)
        {
            path.push_back(cur->right->val);
            traversal(cur->right, count - cur->right->val);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        res.clear();
        path.clear();
        if (root == NULL)
        {
            return res;
        }
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return res;
    }
};
// @lc code=end
