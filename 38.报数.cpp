/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (50.89%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 78.7K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 *  */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        std::string num = "1";
        for (size_t i = 1; i < n; i++)
        {
            num = stringnum(num);
        }
        return num;
    }

private:
    string stringnum(string num)
    {
        if(num.size() ==1)
        {
            return "11";
        }
        std::string result;

        auto iter = num.begin();
        char bak_num = *iter;
        iter++;
        int count = 1;
        for (; iter != num.end(); iter++)
        {
            if (*iter == bak_num)
            {
                count++;
                continue;
            }
            else
            {
                result.append(std::to_string(count));
                result.push_back(bak_num);
                bak_num = *iter;
                count = 1;
            }
        }
        result.append(std::to_string(count));
        result.push_back(bak_num);
        return result;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution sol;
//     sol.countAndSay(4);
//     return 0;
// }
