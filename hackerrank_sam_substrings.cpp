// ONLY FOR SMALL CASES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main()
{
    long long int finalResult = 0;
    string inputString;
    cin >> inputString;
    for (int len = 1; len <= inputString.length(); len++)
    {
        for (int i = 0; i < inputString.length()-len+1; i++)
        {
            string initString = inputString.substr(i, len);
            finalResult += stoll(initString);
        }
    }
    std::cout << finalResult%(long long int)MOD << '\n';
    return 0;
}
