/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (38.10%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 26.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
#include <vector>
#include <string>
using std::vector;

int min(int a, int b)
{
    return a > b ? b : a;
}

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maximal = 0;
        vector<vector<int>> dp;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            vector<int> tmp;
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                tmp.push_back(matrix[i][j] - '0');
                if(matrix[i][j] - '0' == 1)
                {
                    maximal = 1;
                }
            }
            dp.push_back(tmp);
        }

        for (size_t i = 1; i < matrix.size(); i++)
        {
            for (size_t j = 1; j < matrix[0].size(); j++)
            {
                if (dp[i][j] == 1)
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                if (dp[i][j] > maximal)
                {
                    maximal = dp[i][j];
                }
            }
        }
        return maximal * maximal;
    }
};
