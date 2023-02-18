#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX_N = 20;

int n;
int adj[MAX_N][MAX_N] = {};

void dfs(int u, vector<int> &vis) {
    vis[u] = true;
    for (int v = 1; v <= n; ++v)
        if (adj[u][v] && !vis[v])
            dfs(v, vis);
}

int main(void) {
    int m, l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (adj[x][y])
            printf("%d %d parallel edge\n", x, y);
        assert(!adj[x][y]);
        adj[x][y] = adj[y][x] = true;
    }
    vector<int> vis(n, false);
    dfs(0, vis);
    for (int i = 0; i < n; ++i)
        if (!vis[i]) {
            printf("%d not connected to 0\n", i);
            assert(vis[i]);
        }
    return 42;
}
