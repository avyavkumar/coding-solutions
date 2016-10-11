#include <bits/stdc++.h>

using namespace std;

void merge(vector <long long int> list, int p, int q, int r, long long int &count)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector <long long int> left(n1+1);
    vector <long long int> right(n2+1);

    for (int i = 0; i < n1; i++)
        left[i] = list[p+i];

    for (int j = 0; j < n2; j++)
        right[j] = list[q+j+1];

    left[n1] = numeric_limits<long long int>::max();
    right[n2] = numeric_limits<long long int>::max();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
            list[k] = left[i++];
        else
        {
            list[k] = right[j++];
            count++;
        }
    }
}

void get_inversions(vector <long long int> list, int p, int r, long long int &count)
{
    if (p < r)
    {
        int q = p + (r-p)/2;
        get_inversions(list,p,q,count);
        get_inversions(list,q+1,r,count);
        merge(list,p,q,r,count);
    }
}

int main()
{
    vector <long long int> list;
    int test;
    scanf("%d", &test);
    while(test--)
    {
        int number;
        scanf("%d", &number);
        while(number--)
        {
            int x;
            scanf("%d", &x);
            list.push_back(x);
        }
        // code
        long long int count = 0;
        get_inversions(list,0,list.size()-1,count);
        printf("%lld\n", count);
        list.clear();
    }
}
