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
  bool isPalindrome(string s) {
    int n = s.length();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      while (i < j && !isalnum(s[i])) {
        ++i;
      }
      while (i < j && !isalnum(s[j])) {
        --j;
      }
      if (i >= j) {
        return true;
      }
      if (tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }
};
