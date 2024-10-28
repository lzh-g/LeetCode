/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <vector>
#include <stack>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        // 后缀表达式
        stack<int> m_stack;
        for (auto &&it : tokens)
        {
            if (it == "+" || it == "-" || it == "*" || it == "/")
            {
                int num1 = m_stack.top();
                m_stack.pop();
                int num2 = m_stack.top();
                m_stack.pop();
                if (it == "+")
                {
                    m_stack.push(num2 + num1);
                }
                if (it == "-")
                {
                    m_stack.push(num2 - num1);
                }
                if (it == "*")
                {
                    m_stack.push(num2 * num1);
                }
                if (it == "/")
                {
                    m_stack.push(num2 / num1);
                }
            }
            else
            {
                m_stack.push(stoi(it));
            }
        }
        return m_stack.top();
    }
};
// @lc code=end
