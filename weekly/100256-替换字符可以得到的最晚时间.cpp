#include "header.h"

class Solution {
  string handleHour(string s) {
    if (s == "??") {
      return "11";
    }
    if (s[0] == '?') {
      // s[1] != '?'
      if (s[1] >= '2') {
        s[0] = '0';
        return s;
      }
      s[0] = '1';
      return s;
    }
    if (s[1] == '?') {
      if (s[0] == '0') {
        s[1] = '9';
        return s;
      }
      s[1] = '1';
      return s;
    }
    return s;
  }

  string handleMin(string s) {
    if (s == "??") {
      return "59";
    }
    if (s[0] == '?') {
      s[0] = '5';
      return s;
    }
    if (s[1] == '?') {
      s[1] = '9';
      return s;
    }
    return s;
  }

 public:
  string findLatestTime(string s) {
    string hour = handleHour(s.substr(0, 2));
    string min = handleMin(s.substr(3, 2));
    return hour + ":" + min;
  }
};
