/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int LeftBorder = GetLeftBorder(nums, target);
        int RightBorder = GetRightBorder(nums, target);

        if (LeftBorder == -2 || RightBorder == -2)
        {
            return {-1, -1};
        }
        if (RightBorder - LeftBorder > 1)
        {
            return {LeftBorder + 1, RightBorder - 1};
        }
        return {-1, -1};
    }

private:
    // 寻找左边界
    int GetLeftBorder(const vector<int> &nums, const int target)
    {
        int LeftBorder = -2;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
                LeftBorder = right;
            }
        }
        return LeftBorder;
    }

    int GetRightBorder(const vector<int> &nums, const int target)
    {
        int RightBorder = -2;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
                RightBorder = left;
            }
        }
        return RightBorder;
    }
};
// @lc code=end
