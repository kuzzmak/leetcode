#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

        stack<char> ops;
        stack<int> nums;
        int sSize = s.size();
        int currIdx = 0;
        while (currIdx < sSize)
        {
            if (s[currIdx] == '+' || s[currIdx] == '(' || s[currIdx] == ')')
            {
                ops.push(s[currIdx]);
            }
            else if (s[currIdx] == '-')
            {
                if (s[currIdx + 1] != '(')
                {
                    int num = atoi(&s[currIdx + 1]);
                    nums.push(-num);
                    currIdx++;
                    ops.push('+');
                }
            }
            else
            {
                int num = atoi(&s[currIdx]);
                nums.push(num);
            }
            currIdx++;
        }

        while (true)
        {
            if (ops.empty())
                break;

            char op = ops.top();

            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            if (op == '+')
            {
                nums.push(num1 + num2);
            }
            else if (op == '-')
            {
                nums.push(num1 - num2);
            }
            
            ops.pop();
        }
        return 0;
    }
};

int main()
{
    string s("1 + 1");
    s = "(1+(4+5+2)-3)+(6+8)";
    // s = "1 + (4 + 3)";
    // s = " 2-1 + 2 ";
    Solution solution;
    auto res = solution.calculate(s);
    cout << "res: " << res << endl;
    return 0;
}
