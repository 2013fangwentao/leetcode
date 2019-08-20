/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.29%)
 * Likes:    649
 * Dislikes: 0
 * Total Accepted:    125.8K
 * Total Submissions: 223.5K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::vector<int> num_quene;
        int remain_num = x;
        long long int result_num = 0;
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        while (remain_num != 0)
        {
            num_quene.push_back(remain_num % 10);
            remain_num = int(remain_num / 10);
        }
        for (auto index_num : num_quene)
        {
            result_num *= 10;
            result_num += index_num;
        }
        if (result_num == x)
            return true;
        else
            return false;
    }
};
