#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
  if (grid.empty() || grid[0].empty()) {
    return -1;
  }

  int rows, cols;

  rows = grid.size();
  cols = grid[0].size();

  if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
    return -1;
  }

  vector<vector<int>> visited(rows, vector<int>(cols, -1));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        visited[i][j] = 1;
      } else {
        visited[i][j] = 0;
      }
    }
  }
  vector<vector<int>> directions = {
      {0, 1},  // Right
      {0, -1}, // Left
      {1, 0},  // Down
      {-1, 0}, // Up
      {1, 1},  // Down-Right
      {1, -1}, // Down-Left
      {-1, 1}, // Up-Right
      {-1, -1} // Up-Left
  };
  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = 1;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int i = p.first;
    int j = p.second;

    for (auto &dir : directions) {
      int new_i = i + dir[0];
      int new_j = j + dir[1];
      if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols &&
          visited[new_i][new_j] == 0) {
        q.push({new_i, new_j});
        visited[new_i][new_j] = 1 + visited[i][j];
      }
    }
  }
  if (visited[rows - 1][cols - 1] == 0)
    return -1;

  return visited[rows - 1][cols - 1];
}
int main() {
  // input
  int rows, cols;
  cin >> rows;
  cin >> cols;
  vector<vector<int>> grid(rows, vector<int>(cols, 0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
  // solution
  int ans = shortestPathBinaryMatrix(grid);
  cout << ans;
  return 0;
}