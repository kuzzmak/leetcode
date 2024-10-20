#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                    return false;

                char top = stack.top();
                stack.pop();
                
                if (c == ')')
                {
                    if (top != '(')
                        return false;
                }
                else if(c == '}')
                {
                    if (top != '{')
                        return false;
                }
                else
                {
                    if (top != '[')
                        return false;
                }
            }
        }
        return stack.empty();
    }
};

int main()
{
    string s("()");
    s = "()[]{}";
    s = "(]";
    Solution solution;
    auto res = solution.isValid(s);
    std::cout << "res: " << res << std::endl;
    return 0;
}