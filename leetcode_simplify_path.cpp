#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> currentDir;
        int i = 0;
        currentDir.push("/");
        while (i < path.length())
        {
            if (path[i] == '/')
            {
                string tempDir = "";
                i++;
                while (path[i] != '/' && i < path.length())
                {
                    tempDir += path[i];
                    i++;
                }
                if (tempDir.compare("..") == 0)
                {
                    if (currentDir.top() != "/")
                        currentDir.pop();
                }
                else if (tempDir.compare(".") == 0) continue;
                else if (tempDir.compare("/") == 0) continue;
                else if (tempDir.compare("") == 0) continue;
                else
                    currentDir.push(tempDir);
            }
        }
        string finalResult = "";
        while (currentDir.size() > 1)
        {
            if (finalResult.empty())
                finalResult = currentDir.top();
            else
                finalResult = currentDir.top() + "/" + finalResult;
            currentDir.pop();
        }
        return "/" + finalResult;
    }
};
