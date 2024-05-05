#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // s 只包含小写英文字母
  int minAnagramLength(string s) {
    int n = s.length();
    vector<int> c2times(26, 0);
    for (auto &c : s) {
      c2times[c - 'a']++;
    }
    vector<int> appear(26, 0);
    int ans = n;
    for (int i = 0; i < n; ++i) {
      appear[s[i] - 'a']++;
      c2times[s[i] - 'a']--;
      bool ok = true;
      int times = -1;
      for (int j = 0; j < 26; ++j) {
        if (appear[j] == 0 && c2times[j] == 0) {
          continue;
        }

        if (appear[j] != 0 && c2times[j] == 0 || appear[j] == 0 && c2times[j] != 0) {
          ok = false;
          break;
        }
        // 两者都不为 0
        if (c2times[j] % appear[j] != 0) {
          ok = false;
          break;
        }
        if (times == -1) {
          times = c2times[j] / appear[j];
        } else {
          int temp = c2times[j] / appear[j];
          if (temp != times) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        ans = min(ans, i + 1);
      }
    }
    return ans;
  }
};
