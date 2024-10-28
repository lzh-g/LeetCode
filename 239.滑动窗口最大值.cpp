/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution
{
private:
    class MyQueue
    {
    public:
        deque<int> m_que;

        // 比较队头元素和与滑动窗口移除的元素，仅当相等时移除
        void pop(int value)
        {
            if (!m_que.empty() && m_que.front() == value)
            {
                m_que.pop_front();
            }
        }

        // 比较队尾元素与晃动窗口加入的元素，保证单调队列递减
        void push(int value)
        {
            while (!m_que.empty() && m_que.back() < value)
            {
                m_que.pop_back();
            }
            m_que.push_back(value);
        }

        int front()
        {
            return m_que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 单调递减队列，构建一个自定义队列（基于双端队列），那么队首元素一定是当前滑动窗口的最大值，如果滑动窗口移动时把最大值移出去，那么队首元素出队；入队也只入值较大的元素，保证队列递减
        MyQueue m_q;
        vector<int> res;
        // 先将前k个元素放进去
        for (int i = 0; i < k; i++)
        {
            m_q.push(nums[i]);
        }
        res.push_back(m_q.front()); // 这是第一个答案
        for (int i = k; i < nums.size(); i++)
        {
            m_q.pop(nums[i - k]);
            m_q.push(nums[i]);
            res.push_back(m_q.front());
        }
        return res;
    }
};
// @lc code=end
