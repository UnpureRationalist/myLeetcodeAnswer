#include <bits/stdc++.h>
using namespace std;

struct Player {
 public:
  int total_score{0};
  int conti_score{0};
  vector<int> lose_idx{};
  int id{0};

  bool operator<(const Player &rop) const {
    if (this->total_score != rop.total_score) {
      return this->total_score > rop.total_score;
    }
    if (this->conti_score != rop.conti_score) {
      return this->conti_score > rop.conti_score;
    }
    if (this->lose_idx != rop.lose_idx) {
      return this->lose_idx > rop.lose_idx;
    }
    return this->id < rop.id;
  }

  void show() const {
    cout << "id: " << id << " total: " << total_score << " continue: " << conti_score << " lose_idx: ";
    for (auto &idx : lose_idx) {
      cout << idx << " ";
    }
    cout << endl;
  }
};

Player str2Player(const string &s, int id) {
  Player player;
  player.id = id;
  int n = s.length();
  int conti = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++player.total_score;
      ++conti;
      player.conti_score = max(player.conti_score, conti);
    } else {
      player.lose_idx.push_back(i);
      conti = 0;
    }
  }
  return player;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  int m;
  cin >> n >> m;
  vector<Player> players(n);
  for (int i = 0; i < n; ++i) {
    string temp;
    cin >> temp;
    players[i] = str2Player(temp, i + 1);
  }
  std::sort(players.begin(), players.end());

  //   for (const auto &player : players) {
  //     player.show();
  //   }

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << players[i].id;
  }
  cout << endl;
  return 0;
}
