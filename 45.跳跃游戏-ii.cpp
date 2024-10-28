/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // 方法一：判断当前覆盖范围与下次覆盖范围，若当前覆盖范围到了范围最远处还没到终点，那么步数+1（因为在这个步数范围内，跳到哪里都是1次），然后更新
        // if (nums.size() == 1)
        // {
        //     return 0;
        // }
        // int curCover = 0; // 当前覆盖距离最大下标
        // int res = 0;
        // int nextCover = 0; // 下一步覆盖距离最大下标

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     nextCover = max(nums[i] + i, nextCover);
        //     if (i == curCover)
        //     {
        //         res++;
        //         curCover = nextCover;
        //         if (nextCover >= nums.size() - 1)
        //         {
        //             break;
        //         }
        //     }
        // }
        // return res;

        // 方法二，下标只需要移动到倒数第二个数，如果下标到了当前最大覆盖范围，加一，如果没到当前最大覆盖范围就到了倒数第二个，那最后一个肯定已经覆盖到了，不用加一
        int curCover = 0;
        int nextCover = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nextCover = max(nextCover, nums[i] + i);
            if (i == curCover)
            {
                curCover = nextCover;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
