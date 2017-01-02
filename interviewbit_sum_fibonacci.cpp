#include <bits/stdc++.h>

using namespace std;

int fibsum(int N)
{
    vector<int> Fib;
    Fib.push_back(1);
    Fib.push_back(1);
    for(int i = 2; Fib[i - 1] < N; ++i)
    {
        int data = Fib[i - 1] + Fib[i - 2];
        Fib.push_back(data);
    }

    int ans = 0;
    int index = Fib.size() - 1;
    while (N > 0)
    {
        while (Fib[index] > N) index--;
        N -= Fib[index];
        ans++;
    }
    return ans;
}
