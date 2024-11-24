/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        // 创建一个哈希表记录每个数在哪些列表里出现
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int numMax = INT_MIN, numMin = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (auto &&num : nums[i])
            {
                indices[num].push_back(i);
                numMin = min(numMin, num);
                numMax = max(numMax, num);
            }
        }

        // 滑动窗口
        int inside = 0; // inside用来记录
        int left = numMin, right = numMin - 1;
        int ansLeft = numMin, ansRight = numMax;
        vector<int> freq(n); // freq[i]记录当前记录的最短区间中列表i的数字出现了几次
        while (right < numMax)
        {
            right++;
            // 如果当前的右边界是列表中的某个数
            if (indices.count(right))
            {
                for (auto &&index : indices[right])
                {
                    ++freq[index];
                    // 若区间index中首次出现该数字
                    if (freq[index] == 1)
                    {
                        ++inside;
                    }
                }
                // 若inside达到了列表数
                while (inside == n)
                {
                    // 选择区间小的
                    if (right - left < ansRight - ansLeft)
                    {
                        ansLeft = left;
                        ansRight = right;
                    }
                    // 如果当前的左边界是列表中的某个数
                    if (indices.count(left))
                    {
                        // 左边界要右移时，要把左边界的数从freq中移除
                        for (auto &&index : indices[left])
                        {
                            --freq[index];
                            if (freq[index] == 0)
                            {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }
        return {ansLeft, ansRight};
    }
};
// @lc code=end
