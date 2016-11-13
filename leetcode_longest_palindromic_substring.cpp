class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0 || s.empty())
            return "";

        std::vector<std::vector<bool>> dp(s.length());
        for (int i = 0; i < s.length(); i++)
            dp[i].resize(s.length());

        int maxLength = 1;
        string longest = "";
        for (int l = 0; l < s.length(); l++)
        {
            for (int i = 0; i < s.length()-1; i++)
            {
                int j = i+l;
                if (s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1] == true))
                {
                    dp[i][j] = true;

                    if (j-i+1 > maxLength)
                    {
                        maxLength = j-i+1;
                        longest = s.substr(i,maxLength);
                    }
                }
            }
        }

        return longest;
    }
};
