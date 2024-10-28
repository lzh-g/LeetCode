/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <iostream>
#include <string>
#include <vector>
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
    // void traversal(TreeNode *cur, vector<int> &path, vector<string> &res)
    // {
    //     path.push_back(cur->val); // 中
    //     // 找到了叶子节点
    //     if (cur->left == NULL && cur->right == NULL)
    //     {
    //         string sPath;
    //         for (int i = 0; i < path.size() - 1; i++)
    //         {
    //             sPath += to_string(path[i]);
    //             sPath += "->";
    //         }
    //         sPath += to_string(path[path.size() - 1]);
    //         res.push_back(sPath);
    //         return;
    //     }
    //     if (cur->left)
    //     {
    //         traversal(cur->left, path, res);
    //         path.pop_back();
    //     }
    //     if (cur->right)
    //     {
    //         traversal(cur->right, path, res);
    //         path.pop_back();
    //     }
    // }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        // // 回溯法
        // vector<string> res;
        // vector<int> path;
        // if (root == NULL)
        // {
        //     return res;
        // }
        // traversal(root, path, res);
        // return res;

        // 迭代法
        stack<TreeNode *> treeSt; // 保存遍历节点
        stack<string> pathSt;     // 保存路径节点
        vector<string> res;
        if (root == NULL)
        {
            return res;
        }
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty())
        {
            TreeNode *node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node->left == NULL && node->right == NULL)
            {
                res.push_back(path);
            }
            if (node->right)
            {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left)
            {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return res;
    }
};
// @lc code=end
