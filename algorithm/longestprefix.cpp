/************************************************************************************************
@filename    :longestprefix.cpp
@brief       :
@time        :2021/01/19 21:51:35
@author      :hscoder
@versions    :1.0
@email       :hscoder@163.com
@usage       :最长公共前缀
***********************************************************************************************/



#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        int count = strs.size();
        std::string first_str = strs[0];
        int length = first_str.length();

        for (int i = 0; i < length; ++i)
        {
            char c = first_str[i];
            for (int j = 0; j < count; ++j)
            {
                if (i == strs[j].length() - 1 || strs[j][i] != c)
                {
                    return first_str.substr(0, i);
                }
            }
        }

        return "";
    }
};

int main(int argc, char **argv)
{
    std::vector<std::string> vec_str = {"flower", "flow", "flight"};
    Solution solution;
    std::string prefix_str = solution.longestCommonPrefix(vec_str);

    std::cout << prefix_str << std::endl;

    return 1;
}