#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

ll mem[510][510];
ll dp(int n, int m) {
    if (mem[n][m] != -1) {
        return mem[n][m];
    }
    ll mx = 0;
    for (int k = 2; k <= n && k*(k-1)/2 <= m; k += 2) {
        mx = max(mx, dp(n-k, m-k*(k-1)/2) + k * (1LL<<k));
    }
    return mem[n][m] = mx;
}

void rec(int n, int m) {
    ll mx = dp(n,m);
    if (mx == 0) {
        return;
    }
    // for (int k = 1; k <= n && k*(k-1)/2 <= m; k++) {
    for (int k = 2; k <= n && k*(k-1)/2 <= m; k += 2) {
        if (dp(n-k, m-k*(k-1)/2) + k * (1LL<<k) == mx) {
            cout << k << " ";
            rec(n-k, m-k*(k-1)/2);
            break;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(mem,-1,sizeof(mem));
    cerr << dp(n,m) << endl;
    rec(n,m);
    cout << endl;

    return 0;
}

