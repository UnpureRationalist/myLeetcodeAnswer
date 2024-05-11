#include <bits/stdc++.h>
using namespace std;

vector<int> getNext(const string &s) {
  int len = s.length();
  vector<int> next(len, -1);
  int j = -1;
  for (int i = 1; i < len; ++i) {
    while (j != -1 && s[i] != s[j + 1]) {
      j = next[j];
    }
    if (s[i] == s[j + 1]) {
      j++;
    }
    next[i] = j;
  }
  return next;
}

bool kmp(const string &text, const string &pattern) {
  int n = text.length();
  int m = pattern.length();
  vector<int> next = getNext(pattern);
  int j = -1;
  for (int i = 0; i < n; ++i) {
    while (j != -1 && text[i] != pattern[j + 1]) {
      j = next[j];
    }
    if (text[i] == pattern[j + 1]) {
      j++;
    }
    if (j == m - 1) {
      return true;
    }
  }
  return false;
}

void Test1() {
  string text = "abababaabc";
  string pattern = "abababaab";
  bool has = kmp(text, pattern);
  bool expected = text.find(pattern) != string::npos;
  if (has != expected) {
    cout << "Test failed!" << endl;
  } else {
    cout << "Test passed." << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  Test1();
  return 0;
}
