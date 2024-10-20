#include <iostream>
#include <vector>

class Solution2
{
public:
    int trap(std::vector<int> &height)
    {
        int heightSize = height.size();
        bool start = false;
        int water = 0;
        int nextHeight = 0;
        bool nextHeightSet = false;

        // check from
        while (true)
        {
            for (int i = nextHeight; i < heightSize; i++)
            {
                if (height[i] <= 0)
                {
                    if (!start)
                    {
                        continue;
                    }
                    else
                    {
                        water++;
                    }
                }
                else
                {
                    if (!start)
                    {
                        start = true;
                    }
                    if (height[i] != 1 && !nextHeightSet)
                    {
                        nextHeightSet = true;
                        nextHeight = i;
                    }
                    height[i]--;
                }
            }

            start = false;
            nextHeightSet = false;
        }
        return 0;
    }
};

class Solution3
{
public:
    int trap(std::vector<int> &height)
    {
        int heightSize = height.size();
        int water = 0;

        if (heightSize == 1)
            return water;

        int start = 0;
        int end = heightSize - 1;

        int min = 10e5;
        int max = 0;
        for (int i = start; i <= end; i++)
        {
            if (height[i] != 0)
            {
                if (height[i] < min)
                {
                    min = height[i];
                }
                if (height[i] > max)
                {
                    max = height[i];
                }
            }
        }

        for (int i = start; i <= end; i++)
        {
            height[i] -= min;
            if (height[i] < 0)
            {
                water -= height[i];
            }
        }

        // std::cout << "min: " << min << std::endl;
        // std::cout << "max: " << max << std::endl;
        // std::cout << "water: " << water << std::endl;
        while (true)
        {
            for (int i = start; i <= end; i++)
            {
                if (height[i] != 0)
                {
                    start = i;
                    break;
                }
            }

            for (int i = end; i >= start; i--)
            {
                if (height[i] != 0)
                {
                    end = i;
                    break;
                }
            }

            if (start >= end)
                break;

            if (height[start] == 0 || height[end] == 0)
                break;

            for (size_t i = start; i <= end; i++)
            {
                if (height[i] <= 0)
                {
                    water++;
                }
                else
                {
                    height[i]--;
                }
            }
        }
        return water;
    }
};

class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int leftPos = 0;
        int rightPos = height.size() - 1;
        int leftHeight = 0;
        int rightHeight = 0;
        int water = 0;

        while (leftPos < rightPos)
        {
            leftHeight = std::max(leftHeight, height[leftPos]);
            rightHeight = std::max(rightHeight, height[rightPos]);
            if (leftHeight < rightHeight)
            {
                water += leftHeight - height[leftPos++];
            }
            else
            {
                water += rightHeight - height[rightPos--];
            }
        }

        return water;
    }
};

int main()
{
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    height = {4, 2, 0, 3, 2, 5};
    // height = {0};
    // height = {1, 1};
    // height = {2, 0, 2};
    height = {3, 0, 2, 0, 1};
    Solution solution;
    auto res = solution.trap(height);
    std::cout << "res: " << res << std::endl;
    return 0;
}