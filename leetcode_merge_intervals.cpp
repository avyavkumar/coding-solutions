#include <bits/stdc++.h>

using namespace std;

bool sortingFunc(Interval a, Interval b)
{
    if ( b.start != a.start)
        return b.start > a.start;
    else
        return b.end > a.end;
}

class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        sort(intervals.begin(), intervals.end(), sortingFunc);
        
        std::vector<Interval> finalResult;

        if (intervals.size() == 0)
            return finalResult;

        int startIndex = 0, endIndex = 0;
        int endTime = intervals[0].end; int startTime = intervals[0].start;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].end >= endTime && intervals[i].start <= endTime)
            {
                endIndex = i;
                endTime = intervals[i].end;
            }
            if (intervals[i].start >= startTime && intervals[i].end <= endTime)
                continue;
            else
            {
                Interval temp(intervals[startIndex].start,intervals[endIndex].end);
                finalResult.push_back(temp);
                startIndex = i; endIndex = i;
                startTime = intervals[i].start; endTime = intervals[i].end;
            }
        }

        Interval temp(startTime,endTime);
        finalResult.push_back(temp);

        return finalResult;
    }
};
