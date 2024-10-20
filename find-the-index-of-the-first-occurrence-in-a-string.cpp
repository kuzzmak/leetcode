#include <iostream>
#include <string>


class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        int index = -1;
        for (int i = 0; i < haystack_size; i++)
        {
            if (haystack[i] == needle[0])
            {
                bool ok = true;
                for (int j = 0; j < needle_size; j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    index = i;
                    return index;
                }
            }
        }
        return index;
    }
};

int main()
{
    std::string haystack = "hello";
    std::string needle = "ll";
    Solution sol;
    int res = sol.strStr(haystack, needle);
    std::cout << res << std::endl;
}