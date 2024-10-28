/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
        {
            return false;
        }

        stack<char> m_stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                m_stack.push(')');
            }
            else if (s[i] == '[')
            {
                m_stack.push(']');
            }
            else if (s[i] == '{')
            {
                m_stack.push('}');
            }
            // 若栈已空或栈顶元素不匹配
            else if (m_stack.empty() || m_stack.top() != s[i])
            {
                return false;
            }
            else
            {
                m_stack.pop();
            }
        }
        return m_stack.empty();
    }
};
// @lc code=end
