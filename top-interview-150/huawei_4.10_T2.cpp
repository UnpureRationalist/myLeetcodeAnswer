#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int calScore(const vector<vector<int>> &matrix, const vector<int> &subset) {
  int n = subset.size();
  int similarity = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      similarity += matrix[subset[i]][subset[j]];
    }
  }
  return similarity;
}

void search(const vector<vector<int>> &matrix, int idx, vector<char> &visited, vector<int> &subset) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    if (!visited[i] && matrix[idx][i] > 0) {
      visited[i] = 1;
      subset.emplace_back(i);
      search(matrix, i, visited, subset);
    }
  }
}

void solve(const vector<vector<int>> &matrix, vector<int> &answer) {
  int n = matrix.size();
  vector<char> visited(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      visited[i] = 1;
      vector<int> subset;
      subset.emplace_back(i);
      search(matrix, i, visited, subset);
      answer.emplace_back(calScore(matrix, subset));
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }
  vector<int> answer;
  solve(matrix, answer);
  sort(answer.begin(), answer.end(), greater<int>());
  cout << answer[0];
  for (int i = 1; i < answer.size(); ++i) {
    cout << " " << answer[i];
  }
  return 0;
}