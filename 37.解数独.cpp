/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isValid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (backtracking(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(const vector<vector<char>> &board, int row, int col, char num)
    {
        // 判断行
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num)
            {
                return false;
            }
        }
        // 判断列
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
            {
                return false;
            }
        }

        // 判断3×3宫内
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == num)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};
// @lc code=end
