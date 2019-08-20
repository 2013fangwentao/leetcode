/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (49.84%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 62.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    void PushBackWord(int dight, vector<string> &letter)
    {
        if (letter.size() == 0)
        {
            for (auto alphabet : key[dight])
            {
                string temp_word{alphabet};
                letter.emplace_back(temp_word);
            }
            return;
        }
        for (auto word = letter.begin(); word != letter.end(); )
        {
            for (auto alphabet : key[dight])
            {
                string temp_word = (*word) + (alphabet);
                word = letter.insert(word, temp_word);
                word++;
            }
            letter.erase(word);
        }
    }

public:
    std::string key[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits)
    {
        std::vector<string> result;
        for (auto nums : digits)
        {
            int dight = nums - '2';
            PushBackWord(dight, result);
        }
        return result;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> test{0, 0, 0, 0};
//     auto result = sol.letterCombinations("23");
// }
