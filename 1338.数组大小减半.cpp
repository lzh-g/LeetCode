/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (auto &&num : arr)
        {
            freq[num]++;
        }

        vector<int> occ;
        for (auto &&[k, v] : freq)
        {
            occ.push_back(v);
        }
        // 按出现次数降序排序
        sort(occ.begin(), occ.end(), greater<int>());
        int cnt = 0, res = 0;
        for (auto &&c : occ)
        {
            cnt += c;
            res++;
            if (cnt * 2 >= n)
            {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
