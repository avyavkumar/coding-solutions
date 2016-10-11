#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int test, index;
    scanf("%lld", &test);
    int array[4];
    array[0] = 192;
    array[1] = 442;
    array[2] = 692;
    array[3] = 942;
    while(test--)
    {
        scanf("%lld", &index);
        printf("%s\n", to_string(index/4) + to_string(array[index%4]));
    }
}
