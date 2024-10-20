#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        std::vector<std::string> words;
        int sSize = s.size();
        int wordSize = 0;
        int startIndex = 0;
        int totalSize = 0;
        for (int i = 0; i < sSize; i++)
        {
            if (s[i] != ' ')
            {
                if (wordSize == 0)
                {
                    startIndex = i;
                }
                wordSize++;

                if (i == sSize - 1)
                {
                    totalSize += wordSize;
                    words.push_back(s.substr(startIndex, wordSize));
                }
            }
            else
            {
                if (wordSize != 0)
                {
                    totalSize += wordSize;
                    words.push_back(s.substr(startIndex, wordSize));
                }
                wordSize = 0;
            }
        }
        std::reverse(words.begin(), words.end());
        int resSize = totalSize + words.size() - 1;
        std::string res(resSize, ' ');
        int wordsSize = words.size();
        int tempIndex = 0;
        for (int i = 0; i < wordsSize; i++)
        {
            int wordSize = words[i].size();
            for (int j = 0; j < wordSize; j++)
            {
                res[tempIndex++] = words[i][j];
            }
            tempIndex++;
        }
        return res;
    }
};

int main()
{
    std::string s("the sky is blue");
    s = "  hello world  ";
    s = "a g o o d   example";
    Solution sol;
    auto res = sol.reverseWords(s);
    std::cout << "sol: " << res << std::endl;
    return 0;
}