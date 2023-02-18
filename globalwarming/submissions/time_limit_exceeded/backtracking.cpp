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
const ll DINF = 1000000000000000000LL;

vii adj[300];
int n;
ll best = DINF;
bool matched[300];

void bt(int at, ll c) {
    if (at == n) {
        best = min(best, c);
        return;
    }
    if (matched[at]) {
        bt(at+1, c);
    } else {
        matched[at] = true;
        iter(it,adj[at]) {
            if (!matched[it->first]) {
                matched[it->first] = true;
                bt(at+1, c+it->second);
                matched[it->first] = false;
            }
        }
        matched[at] = false;
    }
}

int main() {
    int m;
    cin >> n >> m;
    rep(i,0,m) {
        int a, b,c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(ii(b,c));
        adj[b].push_back(ii(a,c));
    }
    bt(0,0);
    if (best == DINF)
        cout << "impossible" << endl;
    else
        cout << best << endl;
    return 0;
}

