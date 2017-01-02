// INCOMPLETE

#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
public:
    std::priority_queue<int, std::vector<int>, less<int>> lessThanMedian;
    std::priority_queue<int, std::vector<int>, greater<int>> moreThanMedian;
    double currentMedian = 0;

    void addNum(int num)
    {
        if (num < currentMedian)        lessThanMedian.push(num);
        else if (num > currentMedian)   moreThanMedian.push(num);
        else if (num == currentMedian)  return;

        if (lessThanMedian.size() == moreThanMedian.size())
            currentMedian = (lessThanMedian.top()+moreThanMedian.top())/2;

        else if (abs(lessThanMedian.size()-moreThanMedian.size()) > 1)
        {
            int index = lessThanMedian.size() + moreThanMedian.size();
            if (index %2 == 0)
            {
                index /= 2;
                if (index + 1 < lessThanMedian.size())
                {
                    priority_queue<int> tempQueue(lessThanMedian); int i = 0;
                    while (i < index-1) tempQueue.pop();
                    int tempResult = tempQueue.top();
                    tempQueue.pop(); tempResult += tempQueue.top();
                    currentMedian = ((double)tempResult)/2;
                }
                else
                {
                    index -= lessThanMedian.size();
                    priority_queue<int, std::vector<int>, greater<int>> tempQueue(moreThanMedian); int i = 0;
                    while (i < index-1) tempQueue.pop();
                    int tempResult = tempQueue.top();
                    tempQueue.pop(); tempResult += tempQueue.top();
                    currentMedian = ((double)tempResult)/2;
                }
            }
            else
            {
                index++;
                index /= 2;
                if (index < lessThanMedian.size())
                {
                    priority_queue<int> tempQueue(lessThanMedian); int i = 0;
                    while (i < index-1) tempQueue.pop();
                    currentMedian = tempQueue.top();
                }
                else
                {
                    index -= lessThanMedian.size();
                    priority_queue<int, std::vector<int>, greater<int>> tempQueue(moreThanMedian); int i = 0;
                    while (i < index-1) tempQueue.pop();
                    currentMedian = tempQueue.top();
                }
            }
        }

        else
        {
            if (lessThanMedian.size() > moreThanMedian.size())
                currentMedian = lessThanMedian.top();
            else
                currentMedian = moreThanMedian.top();
        }
    }

    double findMedian()
    {
        return currentMedian;
    }
};
