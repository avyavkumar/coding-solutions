#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <long long int> list;
    stack <long long int> o_stack;

    int test;
    cin>>test;
    while (test--)
    {
        long long int x;
        cin >> x;
        list.push_back(x);
    }
    for (int i = 0; i < list.size(); i++)
    {
        if (o_stack.empty())
            o_stack.push(list[i]);

        else
        {
            if (o_stack.top() > list[i])
                // push list[i] in the stack
                o_stack.push(list[i]);
            else
            {

                while (!o_stack.empty() && o_stack.top() < list[i])
                {
                    // pop elements of o_stack
                    std::cout << o_stack.top() << " " << list[i] << std::endl;
                    o_stack.pop();
                }
                // store the value at the end
                o_stack.push(list[i]);
            }
        }
    }
    while(!o_stack.empty())
    {
        std::cout << o_stack.top() << " " << "-1" << std::endl;
        o_stack.pop();
    }
}
