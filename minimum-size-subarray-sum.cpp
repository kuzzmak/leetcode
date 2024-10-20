#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int n = nums.size(), ans = n + 1, i = 0, sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                ans = std::min(ans, j + 1 - i);
                sum -= nums[i++];
            }
        }
        return ((ans == n + 1) ? 0 : ans);
    }
};

int main()
{
    int target = 7;
    // target = 4;
    // target = 11;
    // target = 213;
    // target = 15;
    // target = 7;
    std::vector<int> nums{2, 3, 1, 2, 4, 3};
    // nums = {1, 4, 4};
    // nums = {1, 1, 1, 1, 1, 1, 1, 1};
    // nums = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    // nums = {1, 2, 3, 4, 5};
    // nums = {1, 1, 1, 1, 7};
    Solution s;
    int res = s.minSubArrayLen(target, nums);
    std::cout << "res: " << res << std::endl;
    return 0;
}