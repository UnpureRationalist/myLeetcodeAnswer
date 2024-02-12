#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    stack<string> result;
    result.push("");
    stack<char> stk;
    stack<int> nums;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s[i] == ']') {
        stk.pop();
        int num = nums.top();
        nums.pop();
        string temp = result.top();
        result.pop();
        string res;
        while (num--) {
          res += temp;
        }
        result.top().append(res);
      } else if (s[i] == '[') {
        stk.push(s[i]);
        result.push("");
      } else if (s[i] >= '0' && s[i] <= '9') {
        int j = i + 1;
        while (s[j] >= '0' && s[j] <= '9') {
          ++j;
        }
        int num = stoi(s.substr(i, j));
        nums.push(num);
        i = j - 1;
      } else {
        // s[i] in range ['a', 'z']
        result.top().push_back(s[i]);
      }
    }
    return result.top();
  }
};
