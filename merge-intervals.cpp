#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> merged;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &v1, std::vector<int> &v2)
                  { return v1[0] < v2[0]; });
        merged.push_back(intervals[0]);
        int currentIdx = 0;
        size_t intervalsSize = intervals.size();
        while (true)
        {
            if (currentIdx > intervalsSize - 1)
                break;

            auto last = merged[merged.size() - 1];
            auto current = intervals[currentIdx];
            if (current[0] <= last[1])
            {
                merged.pop_back();
                merged.push_back({std::min(current[0], last[0]), std::max(current[1], last[1])});
            }
            else
            {
                merged.push_back(current);
            }
            currentIdx++;
        }
        return merged;
    }
};

int main()
{
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // intervals = {{1, 4}, {4, 5}};
    // intervals = {{1, 4}, {0, 4}};
    intervals = {{1, 4}, {1, 5}};
    // intervals = {{0, 0}, {1, 4}};
    // intervals = {{1, 4}, {0, 0}};
    Solution sol;
    auto merged = sol.merge(intervals);
    for (auto vec : merged)
    {
        for (auto val : vec)
        {
            std::cout << val << " " << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}