/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (70.81%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 54.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        // std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> tmp;
        if (nums.size() == 1)
        {
            tmp.push_back(nums[0]);
            result.push_back(tmp);
            return result;
        }
        else
        {
            for (auto iter = nums.begin(); iter != nums.end(); iter++)
            {
                int value = *iter;
                nums.erase(iter);
                auto tmp_result = permute(nums);
                for (auto &member : tmp_result)
                {
                    tmp = member;
                    tmp.insert(tmp.begin(), value);
                    result.push_back(tmp);
                }
                nums.insert(iter, value);
            }
            return result;
        }
    }
};

// int main(int argc, const char** argv) {
//     Solution sol;
//     vector<int> test{1, 2, 3};
//     auto result = sol.permute(test);
//     return 0;
// }