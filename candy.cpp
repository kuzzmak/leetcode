#include <iostream>
#include <numeric> 
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int ratingsSize = ratings.size();
        std::vector<int> candy(ratingsSize, 1);
        for (int i = 0; i < ratingsSize - 1; i++)
        {
            if (ratings[i + 1] > ratings[i])
            {
                candy[i + 1] = candy[i] + 1;
            }
        }
        for (int i = ratingsSize - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candy[i] = std::max(candy[i], candy[i + 1] + 1);
            }
        }
        return std::accumulate(candy.begin(), candy.end(), 0);
    }
};

int main()
{
    std::vector<int> ratings{1, 0, 2};
    ratings = {1, 2, 2};
    ratings = {1, 2, 87, 87, 87, 2, 1};
    ratings = {1, 3, 4, 5, 2};
    Solution sol;
    int res = sol.candy(ratings);
    std::cout << "candy: " << res << std::endl;

    // std::vector ratings{1, 1, 9, 3, 4, 4};
    // // candy            1  1  4  2  3  2
    // // ratings = {1, 2, 2};
    // ratings = {1, 0, 2};
    

}


// [1, 1, 9, 3, 4]

// [1, 1, 3, 4, 9]