#include <bits/stdc++.h>

using namespace std;

vector <pair <pair<int, string>, int> > unsorted_list;

void merge(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector <pair <pair<int, string>, int> > left(n1+1);
    vector <pair <pair<int, string>, int> > right(n2+1);

    for (int i = 0; i < n1; i++)
        left[i] = unsorted_list[p+i];

    for (int i = 0; i < n2; i++)
        right[i] = unsorted_list[q+i+1];

    left[n1] = make_pair(make_pair(numeric_limits<int>::max(), " "), -1);
    right[n2] = make_pair(make_pair(numeric_limits<int>::max(), " "), -1);

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
   {
       if (left[i].first.first <= right[j].first.first)
       {
           unsorted_list[k] = left[i];
           i++;
       }
       else
       {
           unsorted_list[k] = right[j];
           j++;
       }
   }
}

void merge_sort(int p, int r)
{
    if (p < r)
    {
        int q = p + (r-p)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge(p,q,r);
    }
}

int main()
{
    long long int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int val;
        string input_s;
        cin >> val >> input_s;
        pair <int, string> temp = make_pair(val, input_s);
        if (i < tests/2)
        {
            pair < pair<int, string>, int> final = make_pair(temp, 0);
            unsorted_list.push_back(final);
        }
        else
        {
            pair < pair<int, string>, int> final = make_pair(temp, 1);
            unsorted_list.push_back(final);
        }
    }

    merge_sort(0,unsorted_list.size()-1);

    for (int i = 0; i < unsorted_list.size(); i++)
    {
        if (unsorted_list[i].second == 0)
            std::cout << "-" << " ";
        else
            std::cout << unsorted_list[i].first.second << " ";
    }
    std::cout << std::endl;
}
