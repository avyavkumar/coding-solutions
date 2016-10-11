#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int test_cases;
    cin>>test_cases;
    stack <char> string;
    for (int test = 0; test < test_cases; test++)
    {
        char brackets[1000];
        cin>>brackets;
        int flag = 0;
        for (int i = 0; brackets[i] != '\0'; i++)
        {
            char x = brackets[i];
            if (x == '[' || x == '{' || x == '(')
            {
                string.push(x);
            }
            else if (x == ']' || x == '}' || x == ')')
            {
                if (string.empty())
                {
                    std::cout << "NO" << std::endl;
                    flag++;
                    break;
                }
                char match = string.top();
                string.pop();
                if (match == '(' && x == ')') { }
                else if (match == '{' && x == '}') { }
                else if (match == '[' && x == ']') { }
                else
                {
                    std::cout << "NO" << std::endl;
                    flag++;
                    break;
                }
            }
        }
        if (string.empty() && flag == 0)
            std::cout << "YES" << std::endl;
        else if (!string.empty() && flag == 0)
            std::cout << "NO" << std::endl;
        while (!string.empty())
            string.pop();
    }
}
