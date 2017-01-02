// INCOMPLETE

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        std::map<string,int> hashMap;
        std::vector<int> finalResult;
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
        {
            int count = 1;
            while (words[i] == words[i+1])
            {
                count++; i++;
            }
            hashMap[words[i]] = count;
        }
        std::map<string,int> copyMap(hashMap);

        int reqLength = words[0].length();
        int countWords = 0;
        for (int i = 0; i < s.length(); i++)
        {
            std::vector<string>:: iterator it = find(words.begin(), words.end(), s.substr(i, reqLength));
            if (it != words.end())
            {
                if (copyMap[*it] > 0)
                {
                    i += reqLength-1;
                    copyMap[words[it-words.begin()]]--;
                    for (auto p = copyMap.begin(); p != copyMap.end(); ++p)
                        std::cout << i << " " << p->first << " " << p->second << endl;
                    countWords++;
                    if (countWords == words.size())
                    {
                        // copyMap = hashMap;
                        finalResult.push_back(i-words.size()*reqLength+1);
                        if (copyMap.find(s.substr(i-words.size()*reqLength+1, reqLength)) != copyMap.end())
                            copyMap[s.substr(i-words.size()*reqLength+1, reqLength)]++;
                        countWords--;
                    }
                }
                else
                {
                    copyMap[*it]++;
                    countWords--;
                }
            }
            else
            {
                copyMap = hashMap;
                countWords = 0;
            }
        }

        return finalResult;
    }
};
