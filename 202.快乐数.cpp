/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_set>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        // 无限循环，那么某次循环产生的平方和会重复出现，使用set存储
        unordered_set<int> sums;
        while (true)
        {
            int sum = 0;
            // 算出各位平方和
            while (n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            // 符合快乐数要求
            if (sum == 1)
            {
                return true;
            }
            // 重复出现平方和，进入死循环
            if (sums.find(sum) != sums.end())
            {
                return false;
            }
            else
            {
                sums.insert(sum);
                n = sum;
            }
        }
    }
};
// @lc code=end
