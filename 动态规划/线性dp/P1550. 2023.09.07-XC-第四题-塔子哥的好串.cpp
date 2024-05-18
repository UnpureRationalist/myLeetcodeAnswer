#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  long long res = 0;
  int cnt = 0;
  for (char &ch : s) {
    if (ch == '0') {
      cnt++;
    } else {
      cnt = max(cnt - 1, 0);
    }
    res += cnt;
  }
  cout << res << endl;
  return 0;
}
