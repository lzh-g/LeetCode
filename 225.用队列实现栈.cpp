/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>

using namespace std;
// @lc code=start
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        m_q.push(x);
    }

    int pop()
    {
        // 栈顶队列不为空，把除最后一个元素重新入队
        if (!m_q.empty())
        {
            for (int i = 0; i < m_q.size() - 1; i++)
            {
                int tmp = m_q.front();
                m_q.pop();
                m_q.push(tmp);
            }
        }
        int res = m_q.front();
        m_q.pop();
        return res;
    }

    int top()
    {
        int res = pop();
        m_q.push(res);
        return res;
    }

    bool empty()
    {
        return m_q.empty();
    }

private:
    queue<int> m_q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
