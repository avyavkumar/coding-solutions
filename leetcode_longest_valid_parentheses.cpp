#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        std::stack<int> dp;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                dp.push(i);
            else
            {
                if (!dp.empty())
                {
                    if (s[dp.top()] == '(')
                        dp.pop();
                    else
                        dp.push(i);
                }
                else
                    dp.push(i);
            }
        }
        int finalResult = 0;
        if (dp.empty())
            return s.length();

        int lastVal = s.length(), firstVal = 0;
        while (dp.size() > 0)
        {
            firstVal = dp.top(); dp.pop();
            finalResult = max(lastVal-firstVal-1, finalResult);
            lastVal = firstVal;
        }

        return max(finalResult, lastVal);
    }
};
