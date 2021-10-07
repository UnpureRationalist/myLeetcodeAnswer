#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int getRectangleArea(int x1, int y1, int x2, int y2)
    {
        int length = abs(x1 - x2);
        int width = abs(y1 - y2);
        return length * width;
    }

    bool isInter(int sma1, int big1, int sma2, int big2)
    {
        if (sma1 > sma2)
        {
            swap(sma1, sma2);
            swap(big1, big2);
        }
        return big1 > sma2;
    }

    int getInterArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        bool lengthInter = isInter(min(ax1, ax2), max(ax1, ax2), min(bx1, bx2), max(bx1, bx2));
        bool widthInter = isInter(min(ay1, ay2), max(ay1, ay2), min(by1, by2), max(by1, by2));
        int area = 0;
        if (lengthInter && widthInter)
        {
            vector<int> xs = {ax1, ax2, bx1, bx2};
            vector<int> ys = {ay1, ay2, by1, by2};
            sort(xs.begin(), xs.end());
            sort(ys.begin(), ys.end());
            int length = xs[2] - xs[1];
            int width = ys[2] - ys[1];
            area = length * width;
        }
        return area;
    }

public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = getRectangleArea(ax1, ay1, ax2, ay2);
        int area2 = getRectangleArea(bx1, by1, bx2, by2);
        int interArea = getInterArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        return area1 + area2 - interArea;
    }
};

// 官方题解
class Solution2
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1), overlapHeight = min(ay2, by2) - max(ay1, by1);
        int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
        return area1 + area2 - overlapArea;
    }
};