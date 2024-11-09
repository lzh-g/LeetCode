/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 使用unorder_set，set就是集合，遍历nums2的元素在nums1的集合中进行查找
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto &&it : nums2)
        {
            if (nums_set.find(it) != nums_set.end())
            {
                res.insert(it);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
