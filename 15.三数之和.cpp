/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.07%)
 * Likes:    1136
 * Dislikes: 0
 * Total Accepted:    68.9K
 * Total Submissions: 298.2K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        if (nums.size() == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
            {
                (result.emplace_back(nums));
                return result;
            }
            else
            {
                return result;
            }
        }
        std::sort(nums.begin(), nums.end());
        vector<int>::iterator iter_num = nums.begin();
        while (*iter_num <= 0 && iter_num != (nums.end() - 1))
        {
            if (iter_num != nums.begin() && *iter_num == *(iter_num - 1))
            {
                iter_num++;
                continue;
            }
            // vector<int> temp_group;
            auto iter_left = iter_num + 1;
            auto iter_right = (--nums.end());
            while (iter_left < iter_right)
            {
                if (iter_left != iter_num + 1 && *iter_left == *(iter_left - 1))
                {
                    iter_left++;
                    continue;
                }
                if (iter_right != (--nums.end()) && *iter_right == *(iter_right + 1))
                {
                    iter_right--;
                    continue;
                }
                if (*iter_left + *iter_right + *iter_num == 0)
                {
                    vector<int> num_group{
                        *iter_num, *iter_left,
                        *iter_right};
                    result.emplace_back(num_group);
                    iter_left++;
                    iter_right--;
                }
                else if (*iter_left + *iter_right + *iter_num < 0)
                {
                    iter_left++;
                }
                else
                {
                    iter_right--;
                }
            }
            iter_num++;
        }
        return result;
    }
};

// int main()
// {
//     Solution sol;
//     vector<int> test{0,0,0,0};
//     sol.threeSum(test);
// }
