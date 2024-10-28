/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // 单调栈，st为单调栈，存储下标，栈顶~栈底递增
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            while (st.empty() == false && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
