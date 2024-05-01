#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int m = players.size();
    int n = trainers.size();
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < m && j < n) {
      if (players[i] <= trainers[j]) {
        ++count;
        ++i;
      }
      ++j;
    }
    return count;
  }
};
