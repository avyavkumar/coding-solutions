#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:

    bool isValid(string s)
    {
        int count = 0;
        for (long long int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                count++;
            if (s[i] == ')' && count-- == 0)
                return false;
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s)
    {
        std::vector<string> finalResult;
        std::set<string> done;

        queue <string> container;
        container.push(s);
        bool found = false;
        done.insert(s);
        while (!container.empty())
        {
            string x = container.front();
            container.pop();
            if (isValid(x))
            {
                finalResult.push_back(x);
                found = true;
            }
            if (found)
                continue;
            else
            {
                for (long long int i = 0; i < x.length(); i++)
                {
                    if (x[i] == ')' || x[i] == '(')
                    {
                        string subString = x.substr(0, i) + x.substr(i+1);
                        if (find(done.begin(), done.end(), subString) == done.end())
                        {
                            container.push(subString);
                            done.insert(subString);
                        }
                    }
                }
            }
        }
        return finalResult;
    }
};
