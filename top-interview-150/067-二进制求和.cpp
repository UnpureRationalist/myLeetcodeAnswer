#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length();
        int n = b.length();
        string ans;
        ans.reserve(m + n + 1);
        int pre = 0;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0) {
            int sum = a[i] - '0' + b[j] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            ans.push_back(sum ? '1' : '0');
            --i;
            --j;
        }
        while (i >= 0) {
            int sum = a[i] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            ans.push_back(sum ? '1' : '0');
            --i;
        }
        while (j >= 0) {
            int sum =  b[j] - '0' + pre;
            pre = sum / 2;
            sum = sum % 2;
            ans.push_back(sum ? '1' : '0');
            --j;
        }
        if (pre) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
