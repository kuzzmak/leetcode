#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> vecs;
        for (int i = 1; i <= numRows; i++)
        {
            std::vector<int> temp;
            for (int j = 0; j < i; j++)
            {
                if (j == 0 || j == i - 1)
                {
                    temp.push_back(1);
                }
                else
                {
                    int val = vecs[i - 2][j - 1] + vecs[i - 2][j];
                    temp.push_back(val);
                }

            }
            vecs.push_back(temp);
        }

        for (auto vec : vecs)
        {
            for (auto v : vec)
            {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
        return vecs;
    }
};

int main()
{
    int numRows = 4;
    Solution s;
    auto res = s.generate(numRows);
}