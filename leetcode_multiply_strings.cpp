#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        std::vector<int> tempResult(num1.length()+num2.length(),0);

        for (int i = 0; i < num1.length(); i++)
        {
            for (int j = 0; j < num2.length(); j++)
                tempResult[i+j] += (num1[i] - '0')*(num2[j] - '0');
        }

        string finalResult;

        for (int i = 0; i < num1.length()+num2.length(); i++)
        {
            int product = tempResult[i]%10;
            int carry = tempResult[i]/10;
            if (i+1  >= 0)
                tempResult[i+1] += carry;
            finalResult = to_string(product) + finalResult;
        }

        while (finalResult[0] == '0' && finalResult.length() > 1)
            finalResult.erase(finalResult.begin());

        return finalResult;
    }
};
