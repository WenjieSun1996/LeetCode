class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX, buildingCnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0)), cnt = dist;
        vector<int> dirs{0,-1,0,1,0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++buildingCnt;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int level = 1;
                    while (!q.empty()) {
                        int sz = q.size();
                        for (int s = 0; s < sz; ++s) {
                            auto [a, b] = q.front();
                            q.pop();
                            for (int k = 0; k < 4; ++k) {
                                int x = a + dirs[k], y = b + dirs[k+1];
                                if (x >= 0 && x < m && y >= 0 && y < n && !grid[x][y] && !visited[x][y]) {
                                    dist[x][y] += level;
                                    ++cnt[x][y];
                                    visited[x][y] = true;
                                    q.push({x, y});
                                }
                            }
                        }
                        ++level;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j] && cnt[i][j] == buildingCnt) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};