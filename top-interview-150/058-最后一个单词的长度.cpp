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
  int lengthOfLastWord(string s) {
    int n = s.length();
    int i = n - 1;
    while (i >= 0 && s[i] == ' ') {
      --i;
    }
    int j = i - 1;
    while (j >= 0 && s[j] != ' ') {
      --j;
    }
    return i - j;
  }
};
