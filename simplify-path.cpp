#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int currIdx = 0;
        int pathSize = path.size();
        stack<char> stck;
        while (true)
        {
            if (currIdx > pathSize - 1)
                break;

            char curr = path[currIdx];

            if (curr == '/')
            {
                if (stck.empty())
                {
                    stck.push('/');
                }
                else
                {
                    char top = stck.top();
                    if (top != '/')
                    {
                        stck.push('/');
                    }
                }
            }
            else if (curr == '.')
            {
                int tempCurr = currIdx;
                int dots = 0;
                while (true)
                {
                    if (tempCurr > pathSize - 1)
                        break;

                    if (path[tempCurr] == '.')
                    {
                        dots++;
                    }
                    else
                    {
                        break;
                    }

                    tempCurr++;
                }
                if (dots == 1)
                {
                    if (tempCurr < pathSize)
                    {
                        // "/.hidden"
                        if (path[tempCurr] != '.' && path[tempCurr] != '/')
                        {
                            stck.push('.');
                        }
                        // "/hello./world/"
                        else if (path[currIdx - 1] != '/')
                        {
                            stck.push('.');
                        }
                    }
                }
                else if (dots >= 2)
                {
                    // check for hello..
                    if (tempCurr - dots -1 >= 0)
                    {
                        if (path[tempCurr - dots -1] != '/')
                        {
                            for (int i = 0; i < dots; i++)
                            {
                                stck.push('.');
                            }
                            currIdx += dots;
                            continue;
                        }
                    }

                    if (dots >= 3)
                    {
                        for (int i = 0; i < dots; i++)
                        {
                            stck.push('.');
                        }
                        currIdx += dots - 1;
                    }
                    else if (dots == 2)
                    {
                        // see if there's anything after two dots that's not /
                        if (tempCurr + 1 < pathSize)
                        {
                            if (path[tempCurr] != '/')
                            {
                                stck.push('.');
                                stck.push('.');
                                currIdx += 2;
                                continue;
                            }
                        }
                        if (!stck.empty() && stck.size() > 1)
                        {
                            // remove last /
                            stck.pop();
                            while (stck.top() != '/')
                            {
                                stck.pop();
                            }
                        }

                        currIdx++;
                    }
                }
                else
                {
                    for (int i = 0; i < dots; i++)
                    {
                        stck.push('.');
                    }

                    currIdx += dots - 1;
                }
            }
            else
            {
                stck.push(curr);
            }

            currIdx++;
        }

        if (!stck.empty() && stck.size() > 1 && stck.top() == '/')
        {
            stck.pop();
        }

        std::string res(stck.size(), ' ');
        currIdx = 0;
        while (!stck.empty())
        {
            res[res.size() - 1 - currIdx] = stck.top();
            stck.pop();
            currIdx++;
        }
        return res;
    }
};

int main()
{
    string path("/home/");
    path = "/a/./b/../../c/";
    // path = "/a/../.././../../.";
    // path = "/a/..";
    // path = "/a//b//c//////d";
    // path = "/../hidden";
    path = "/.hidden";
    // path = "/hello../world";
    // path = "/hello./world/";
    path = "/../..ga/b/.f..d/..../e.baaeeh./.a";
    Solution solution;
    auto res = solution.simplifyPath(path);
    cout << "res: " << res << endl;
    return 0;
}