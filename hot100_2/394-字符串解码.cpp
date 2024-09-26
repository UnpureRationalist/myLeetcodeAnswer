#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    int n = s.length();
    stack<string> result;
    result.push("");
    stack<char> symbol;  // stack for '[' and ']'
    stack<int> nums;
    for (int i = 0; i < n; ++i) {
      if (s[i] == ']') {
        // pop and do multiply
        symbol.pop();
        int num = nums.top();
        nums.pop();
        string tmp = result.top();
        result.pop();
        while (num--) {
          result.top().append(tmp);
        }
      } else if (s[i] == '[') {
        symbol.push('[');
        result.push("");
      } else if (isdigit(s[i])) {
        int j = i + 1;
        while (j < n && isdigit(s[j])) {
          ++j;
        }
        int num = stoi(s.substr(i, j - i));
        nums.push(num);
        i = j - 1;
      } else {
        result.top().push_back(s[i]);
      }
    }
    return result.top();
  }
};
