#include <bits/stdc++.h>

using namespace std;

struct Person
{
    string name;
    int height;
    int frontTaller;
};

struct Compare
{
    bool operator()(const Person& a, const Person& b)
    {
        if(a.frontTaller != b.frontTaller) return a.frontTaller < b.frontTaller;
        else return a.height > b.height;
    }
};

list<Person> retrieveQueue(vector<Person>& v)
{
    sort(v.begin(), v.end(), Compare());
    list<Person> q;
    for (int i = 0; i < v.size(); ++ i)
    {
        q.insert(q.begin() + v.frontTaller, q);
    }
    return q;
}
