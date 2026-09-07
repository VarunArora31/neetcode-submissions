class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        auto dfs = [&] (int row, int col, auto &&dfs) -> void{
            vis[row][col] = 1;
            for (int k = 0; k < 4; k++) {
                int nr = row + dx[k], nc = col + dy[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    dfs(nr, nc, dfs);
                }
            }
        };
        int island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    island++;
                    dfs(i, j, dfs);
                }
            }
        }
        return island;
    }
};
