#include <bits/stdc++.h>
using namespace std;

string removeMHY(const string &s) {
    string ans;
    
}

bool legal(const string&s, const string &t) {
    int m = s.length();
    int n = t.length();
    int i = 0;
    int j = 0;
    while (i < m && j < n) {

    }
}

void solve() {
    string s;
    string target;
    cin >> s >> target;
    bool ok = legal(s, target);
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
