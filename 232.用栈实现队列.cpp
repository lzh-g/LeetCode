/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>

using namespace std;
// @lc code=start
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                int tmp = stIn.top();
                stIn.pop();
                stOut.push(tmp);
            }
        }
        int out = stOut.top();
        stOut.pop();
        return out;
    }

    int peek()
    {
        int res = pop();
        stOut.push(res);
        return res;
    }

    bool empty()
    {
        if (stIn.empty() && stOut.empty())
        {
            return true;
        }
        return false;
    }

private:
    stack<int> stIn;
    stack<int> stOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
