/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (53.31%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 35.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
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
                auto find_iter = std::find(nums.begin(), iter, value);
                if (find_iter != iter)
                {
                    continue;
                }

                nums.erase(iter);
                auto tmp_result = permuteUnique(nums);
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
// int main(int argc, char const *argv[])
// {
//     Solution sol;
//     vector<int> test{1, 1, 2};
//     auto result = sol.permuteUnique(test);

//     return 0;
// }
