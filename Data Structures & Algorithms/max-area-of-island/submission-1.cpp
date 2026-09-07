class DSU {
vector<int> parent, size;
public:
  DSU(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
  }  
  int getParent(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = getParent(parent[node]);
  }
  bool add(int u, int v) {
    u = getParent(u);
    v = getParent(v);
    if (u == v) return true;
    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    return false;
  }
  int getSize(int n) {
    return size[getParent(n)];
  }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto index = [&] (int i, int j) {
            return i * m + j;
        };
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        DSU d(n * m);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj]) {
                            d.add(index(i, j) ,index(ni, nj));
                        }
                    }
                    area = max(area, d.getSize(index(i, j)));
                }
            }
        }
        return area;
    }
};
