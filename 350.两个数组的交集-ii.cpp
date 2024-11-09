/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        // 对较短数组构造哈希表，用长数组去检查哈希表找到交集和次数
        if (nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> mp;
        vector<int> ans;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]]++;
        }

        for (size_t i = 0; i < nums2.size(); i++)
        {
            // 遍历nums2时，找到了交集且出现数量少于nums1中，则输出
            if (mp.find(nums2[i]) != mp.end() && mp[nums2[i]] > 0)
            {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;
    }
};
// @lc code=end
