#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        std::sort(citations.begin(), citations.end());
        int citationsSize = citations.size();
        int hIndex = 0;
        for (int i = 0; i < citationsSize; i++)
        {
            if (citations[i] == 0)
            {
                continue;
            }

            int newIndex = std::min(citationsSize - i, citations[i]);
            if (newIndex >= hIndex)
            {
                hIndex = newIndex;
            }
            else
            {
                break;
            }
        }
        return hIndex;
    }
};

int main()
{                                              //   4 3 2 1
    std::vector<int> citations{3, 0, 6, 1, 5}; // 0 1 3 5 6
    // citations = {1, 3, 1};                  // 1 1 3
    // citations = {11, 15};
    // citations = {0};
    // citations = {1, 1};
    // citations = {1, 2, 1, 2};
    Solution s;
    auto res = s.hIndex(citations);
    std::cout << "res: " << res << std::endl;
    return 0;
}

// 0 1 2 3 4
// 0 1 3 5 6
// 5 4 3 2 1
// 11 15
