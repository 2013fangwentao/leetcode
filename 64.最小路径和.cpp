/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.15%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 44.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
#include "stdio.h"
#include <vector>

using std::vector;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                {
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                    continue;
                }
                if (j == 0)
                {
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                    continue;
                }
                grid[i][j] += (grid[i][j - 1] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
