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
  unordered_map<int, char> mp{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};

 public:
  string intToRoman(int num) {
    string ans;
    int power = 1000;
    for (int i = 3; i >= 0; --i) {
      int temp = num / power;
      int bigger = temp * power;
      if (temp != 0) {
        if (temp == 4) {
          ans.push_back(mp[1 * power]);
          ans.push_back(mp[5 * power]);
        } else if (temp == 9) {
          ans.push_back(mp[1 * power]);
          ans.push_back(mp[10 * power]);
        } else if (temp < 4) {
          ans.append(string(temp, mp[power]));
        } else {
          ans.push_back(mp[5 * power]);
          ans.append(string(temp - 5, mp[power]));
        }
      }
      power /= 10;
      num -= bigger;
    }
    return ans;
  }
};

const pair<int, string> valueSymbols[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
    {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"},
};

class Solution {
 public:
  string intToRoman(int num) {
    string roman;
    for (const auto &[value, symbol] : valueSymbols) {
      while (num >= value) {
        num -= value;
        roman += symbol;
      }
      if (num == 0) {
        break;
      }
    }
    return roman;
  }
};

const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
 public:
  string intToRoman(int num) {
    return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
  }
};
