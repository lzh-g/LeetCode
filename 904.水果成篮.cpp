/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
/**
 * 求最长子数组，其种类不超过2
 */
// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int i = 0, ans = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < fruits.size(); j++)
        {
            count[fruits[j]]++;
            while (count.size() > 2)
            {
                auto it = count.find(fruits[i++]);
                --it->second;
                if (it->second == 0)
                {
                    count.erase(it);
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
// @lc code=end
