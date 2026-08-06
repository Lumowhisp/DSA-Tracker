#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int rows, cols;
  cin >> rows;
  cin >> cols;
  vector<vector<int>> grid(rows, vector<int>(cols, 0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
  vector<vector<int>> minutes(rows, vector<int>(cols, -1));
  queue<pair<int, int>> q;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
        minutes[i][j] = 0;
      }
      if (grid[i][j] == 0) {
        minutes[i][j] = -2;
      }
    }
  }
  // bfs
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int i = p.first;
    int j = p.second;
    for (auto &dir : directions) {
      int new_i = i + dir[0];
      int new_j = j + dir[1];
      if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols &&
          grid[new_i][new_j] == 1 && minutes[new_i][new_j] == -1) {
        minutes[new_i][new_j] = 1 + minutes[i][j];
        q.push({new_i, new_j});
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ans = max(ans, minutes[i][j]);
      if (minutes[i][j] == -1) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
  return 0;
}