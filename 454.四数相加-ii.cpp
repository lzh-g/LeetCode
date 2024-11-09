/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 这题和1思路类似
        // 用来存储数组1和2各元素结果之和及其出现次数key(和)-value(和的次数)
        unordered_map<int, int> map;
        for (auto &&i : nums1)
        {
            for (auto &&j : nums2)
            {
                map[i + j]++;
            }
        }

        int count = 0;
        for (auto &&i : nums3)
        {
            for (auto &&j : nums4)
            {
                if (map.find(0 - (i + j)) != map.end())
                {
                    count += map[0 - (i + j)];
                }
            }
        }
        return count;
    }
};
// @lc code=end
