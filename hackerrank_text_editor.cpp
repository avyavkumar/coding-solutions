#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int main()
{
    stack <string> strings;
    int test_cases;
    cin>>test_cases;
    string top_string;

    while(test_cases--)
    {
        int op;
        int length;
        char input[MAX];
        cin >> op;
        if (op == 1)
        {
            cin>>input;
            strings.push(top_string);
            top_string.append(input);
        }
        else if (op == 2)
        {
            cin >> length;
            strings.push(top_string);
            int s_len = top_string.length();
            for (int i = 0; i < length; i++)
                top_string.pop_back();
        }
        else if (op == 3)
        {
            cin >> length;
            std::cout << top_string.at(length-1) << std::endl;
        }
        else if (op == 4)
        {
            top_string = strings.top();
            strings.pop();
        }
    }
}
