#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumOperationsToMakeKPeriodic(string word, int k) {
    int n = word.length();
    unordered_map<string, int> str2times;
    int max_elem = 0;
    for (int i = 0; i < n; i += k) {
      string temp = word.substr(i, k);
      str2times[temp]++;
      max_elem = max(max_elem, str2times[temp]);
    }
    int total = n / k;
    return total - max_elem;
  }
};
