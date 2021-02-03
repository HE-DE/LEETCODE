#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> num2char = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
vector<string> letterCmbs;
string letterCmb;
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {};
    }
    letterCombinationsHelper(0, digits);
    return letterCmbs;
}

void letterCombinationsHelper(int startIndex, string &digits)
{
    if (letterCmb.size() == digits.size())
    {
        letterCmbs.push_back(letterCmb);
        return;
    }
    for (auto &ch : num2char[digits[startIndex]])
    {
        letterCmb.push_back(ch);
        letterCombinationsHelper(startIndex + 1, digits);
        letterCmb.pop_back();
    }
}
