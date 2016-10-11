#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    std::vector<long long int > order;
    while(test--)
    {
        int number;
        scanf("%d", &number);
        while(number--)
        {
            int x;
            scanf("%d", &x);
            order.push_back(x);
        }
        //code
        sort(order.begin(), order.end());
        if (order.size() == 2 && order[0] == 2 && order[1] == 3)
        {
            printf("2 3\n");
        }
        else
        {
            int count1 = 0;
            int used = 0;
            for (int i = 0; i < order.size(); i++)
            {
                if (order[i] == 1)
                {
                    count1++;
                    used = 1;
                    printf("1 ");
                }
            }
            for (int i = order.size()-1; (used == 0)? i > -1 : i >= count1; i--)
                printf("%lld ", order[i]);
            printf("\n");
        }
        order.clear();
    }
}
