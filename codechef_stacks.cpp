#include <bits/stdc++.h>

using namespace std;

int  main()
{
    vector <long long int> head;
    long long int  test_cases;
    cin>>test_cases;
    while(test_cases--)
    {
        long long int  disks;
        cin>>disks;
        for (long long int  i = 0; i < disks; i++)
        {
            long long int  c_disk;
            cin>>c_disk;
            long long int  done = 0;
            long long int  stack_i;
            long long int  min = -1;           // initial condtion
            vector<long long int>::iterator up = upper_bound(head.begin(), head.end(), c_disk);
            if (up != head.end())
                head.at(up-head.begin()) = c_disk;
            else
                head.push_back(c_disk);
        }
        std::cout << head.size() << " ";
        for (long long int  i = 0; i < head.size(); i++)
        {
            cout << head.at(i) << " " ;
        }
        head.clear();
        std::cout << std::endl;
    }
}
