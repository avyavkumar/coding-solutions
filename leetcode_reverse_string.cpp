#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        if (s.length() == 0 || s.empty())
        {
            s = "";
            return;
        }

        reverse(s.begin(), s.end());
        int i = 0;
        int finish = i;

        while (finish < s.length())
        {
            finish = i;
            while(s[finish] != ' ' && finish < s.length()) finish++;
            if (finish < s.length())
                reverse(s.begin()+i, s.begin()+finish);
            if (finish == s.length())
                reverse(s.begin()+i, s.begin()+finish);
            i = finish+1;
        }
    }
};
