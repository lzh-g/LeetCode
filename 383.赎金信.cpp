/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> count(26, 0);

        for (size_t i = 0; i < magazine.size(); i++)
        {
            count[magazine[i] - 'a']++;
        }

        for (size_t i = 0; i < ransomNote.size(); i++)
        {
            count[ransomNote[i] - 'a']--;
        }

        for (size_t i = 0; i < count.size(); i++)
        {
            if (count[i] < 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
