/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (53.56%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 26.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */
#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool first_row = false;
        bool first_col = false;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0)
                        first_row = true;
                    if (j == 0)
                        first_col = true;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                std::for_each(matrix[i].begin() + 1, matrix[i].end(), [&](vector<int>::reference iter) mutable { (iter) = 0; });
            }
        }
        for (size_t i = 1; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                for (size_t j = 1; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
            
        }
        if (first_row)
        {
            std::for_each(matrix[0].begin(), matrix[0].end(), [&](vector<int>::reference iter) mutable { (iter) = 0; });
        }
        if (first_col)
        {
            for (size_t j = 0; j < matrix.size(); j++)
            {
                matrix[j][0] = 0;
            }
        }
    }
};

// int main()
// {
//     vector<vector<int>> matrix;
//     vector<int> temp = {1,0,3};
//     matrix.emplace_back(temp);
//     // matrix.emplace_back(vector<int>{3, 4, 5, 2});
//     // matrix.emplace_back(vector<int>{1, 3, 1, 5});
//     Solution sol;
//     sol.setZeroes(matrix);
// }
