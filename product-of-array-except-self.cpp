#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int numsSize = nums.size();
        std::vector<int> right;
        int tempRes = 1;
        for (int i = 0; i < numsSize; i++)
        {
            tempRes *= nums[i];
            right.push_back(tempRes);
        }

        std::vector<int> left;
        tempRes = 1;
        for (int i = numsSize - 1; i >= 0; i--)
        {
            tempRes *= nums[i];
            left.push_back(tempRes);
        }

        std::vector<int> res;
        for (int i = 0; i < numsSize; i++)
        {

            if (i == 0)
            {
                res.push_back(left[numsSize - 2]);
            }
            else if(i == numsSize - 1)
            {
                res.push_back(right[numsSize - 2]);
            }
            else
            {
                int leftPart = right[i - 1];
                int rightPart = left[numsSize - i - 2];
                res.push_back(leftPart * rightPart);
                // std::cout << "left part: " << leftPart << ", right part: " << rightPart << std::endl;
                // std::cout << "lft: " << left[numsSize - 2 - i] << std::endl;
            }
        }

        // std::cout << "right" << std::endl;
        // for (auto v : right)
        // {
        //     std::cout << v << " ";
        // }
        // std::cout << std::endl;

        // std::cout << "left" << std::endl;
        // for (auto v : left)
        // {
        //     std::cout << v << " ";
        // }
        // std::cout << std::endl;
        
        return res;
    }
};

// 1 - 24
// 2 - 12, 1
// 3 - 4 

int main()
{
    std::vector<int> example{1, 2, 3, 4};
    example = {-1, 1, 0, -3, 3};
    Solution solution;
    auto res = solution.productExceptSelf(example);
    std::cout << "res: " << std::endl;
    for (auto r : res)
    {
        std::cout << r << " ";
    }
    std::cout << std::endl;
    return 0;
}