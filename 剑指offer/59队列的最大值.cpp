#include <iostream>
#include <queue>
using namespace std;

class MaxQueue
{
    queue<int> q;
    int maxElem = -1;
    int maxCount = 0;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (q.empty())
            return -1;
        return maxElem;
    }

    void push_back(int value)
    {
        if (q.empty())
        {
            maxElem = value;
            maxCount = 1;
        }
        else
        {
            if (value == maxElem)
                ++maxCount;
            else if (value > maxElem)
                maxCount = 1;
            maxElem = max(maxElem, value);
        }
        q.push(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        else
        {
            int temp = q.front();
            q.pop();
            if (temp == maxElem)
                --maxCount;
            if (maxCount == 0 && !q.empty())
            {
                maxElem = q.front();
                vector<int> v;
                while (!q.empty())
                {
                    v.push_back(q.front());
                    q.pop();
                }
                for (auto &elem : v)
                    maxElem = max(maxElem, elem);
                for (auto &elem : v)
                    if (elem == maxElem)
                        ++maxCount;
                for (auto &elem : v)
                    q.push(elem);
            }
            return temp;
        }
    }
};

class MaxQueue2
{
    queue<int> q;
    deque<int> d;

public:
    MaxQueue2()
    {
    }

    int max_value()
    {
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value)
    {
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front())
        {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{

    return 0;
}