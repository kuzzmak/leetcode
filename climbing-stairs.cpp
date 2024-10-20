#include <cmath>
#include <iostream>

int bin_coeffs[46][46];

class Solution {
private:
    int bin_coeff(int n, int k)
    {
        if (k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;

        if (bin_coeffs[n][k] != 0)
        {
            return bin_coeffs[n][k];
        }

        int first = bin_coeff(n - 1, k - 1);
        int second = bin_coeff(n - 1, k);

        bin_coeffs[n][k] = first + second;
    
        return first + second;
    }
public:
    int climbStairs(int n) {
        if (n <= 3)
        {
            return n;
        }

        int k = 1;
        int res = 1;
        for (int i = n - 1; i > round(n / 2); i--)
        {
            res += bin_coeff(i, k);
            k++;
        }
        if (n % 2 == 0)
        {
            res += 1;
        }
        return res;
    }
};

int main()
{
    int n = 44;
    Solution sol;
    int res = sol.climbStairs(n);
    std::cout << res << std::endl;
}
