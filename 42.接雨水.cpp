/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> st;
        int res = 0;
        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {

            while (!st.empty() && height[st.top()] < height[i])
            {
                int index = st.top();
                st.pop();
                if (!st.empty())
                {
                    res += (min(height[i], height[st.top()]) - height[index]) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
