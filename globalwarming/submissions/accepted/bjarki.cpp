#include <bits/stdc++.h>
using namespace std;
template <class T> int sz(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 1000000000;
const ll DINF = 1000000000000000000LL;

int cost[510][510];
bool vis[510];
vi comp;
int n;

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = true;
    comp.push_back(cur);
    rep(i,0,n) {
        if (cost[cur][i] != INF) {
            dfs(i);
        }
    }
}

ll mem[1<<25];
ll dp(int left) {
    if (left == 0) {
        return 0;
    }
    if (mem[left] != -1)
        return mem[left];
    int at = 0;
    while (~left & (1<<at)) at++;
    ll res = DINF;
    rep(snd,at+1,sz(comp)) {
        if (~left & (1<<snd)) continue;
        res = min(res, cost[comp[at]][comp[snd]] + dp(left ^ (1<<at) ^ (1<<snd)));
    }
    return mem[left] = res;
}

int main() {
    int m;
    cin >> n >> m;
    rep(i,0,n) {
        rep(j,0,n) {
            cost[i][j] = INF;
        }
    }

    rep(i,0,m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    ll sm = 0;
    rep(i,0,n) {
        if (!vis[i]) {
            comp.clear();
            dfs(i);

            if (sz(comp) % 2 != 0) {
                cout << "impossible" << endl;
                return 0;
            }

            memset(mem,-1,sizeof(mem));
            sm += dp((1<<sz(comp))-1);
        }
    }
    cout << sm << endl;

    return 0;
}

