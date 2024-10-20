#include <iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int size = gas.size();
        int currentGas = 0;
        int resIndex = -1;
        for (int index = 0; index <= size; index++)
        {
            // std::cout << "index: " << index << std::endl;
            bool wholeCircle = false;
            for (int i = 0; i < size; i++)
            {
                int g = gas[(index + i) % size];
                int c = cost[(index + i) % size];
                if (g == 0 && c == 0)
                {
                    index++;
                    break;
                }
                currentGas += g - c;
                if (currentGas < 0)
                {
                    break;
                }
                if (i == size - 1)
                {
                    wholeCircle = true;
                }
                // std::cout << "gas: " << currentGas << ", g: " << g << ", c: " << c << std::endl;
            }
            std::cout << "gas on end: " << currentGas << std::endl;
            if (currentGas >= 0 && wholeCircle)
            {
                return index;
            }
            wholeCircle = false;
            currentGas = 0;
        }
        return -1;
    }
};

int main()
{                              
    std::vector<int> gas{1, 2, 3, 4, 5};
    gas = {0, 0, 0, 1};
    std::vector<int> cost{3, 4, 5, 1, 2};
    cost = {0, 0, 0, 1};
    Solution s;
    auto res = s.canCompleteCircuit(gas, cost);
    std::cout << res << std::endl;
    return 0;
}