#include <bits/stdc++.h>

using namespace std;

int alpha[999];
string strings[100000];

bool sorting_func(string a, string b)
{
    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if (alpha[a[i]] - alpha[b[i]])
            return alpha[a[i]] < alpha[b[i]];
    }
    return a.size() < b.size();
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        char init[1000];
        scanf("%s", init);
        for (int i = 0; init[i] != '\0'; i++)
            alpha[init[i]] = i;
        int total;
        scanf("%d", &total);
        for (int i = 0; i < total; i++)
        {
            scanf("%s", init);
            strings[i] = init;
        }
        sort(strings, strings + total, sorting_func);
        for (int i = 0; i < total; i++)
            printf("%s\n", strings[i].c_str());
        printf("\n");
    }
}
