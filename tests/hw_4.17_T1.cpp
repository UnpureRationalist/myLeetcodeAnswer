#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  list<char> lst;
  char c;
  while (cin >> c) {
    lst.emplace_back(c);
  }
  while (lst.size() >= 3) {
    int n = lst.size();
    int idx = 0;
    list<char>::iterator delete_iter;
    list<char>::iterator end_iter;
    bool found = false;
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
      if (idx + 2 < n) {
        list<char>::iterator backup = iter;
        char first = *iter;
        ++iter;
        char second = *iter;
        ++iter;
        char third = *iter;
        if (first == second && second == third) {
          found = true;
          delete_iter = backup;
          ++iter;
          end_iter = iter;
          break;
        }
        iter = backup;
      }
      ++idx;
    }
    if (found) {
      lst.erase(delete_iter, end_iter);
    } else {
      break;
    }
  }
  if (lst.size() == 0) {
    cout << 0 << endl;
  } else {
    for (auto c : lst) {
      cout << c << " ";
    }
    cout << endl;
  }
  return 0;
}