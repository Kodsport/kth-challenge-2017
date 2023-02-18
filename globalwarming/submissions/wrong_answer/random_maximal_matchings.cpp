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

bool matched[250];

int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<ii,int> > es;
    rep(i,0,m) {
        int a,b,c;
        cin >> a >> b >> c;
        a--, b--;
        es.push_back(make_pair(ii(a,b),c));
    }
    ll best = DINF;
    rep(it,0,100000) {
        random_shuffle(es.begin(), es.end());
        memset(matched,0,sizeof(matched));
        ll cur = 0;
        iter(it,es) {
            if (!matched[it->first.first] && !matched[it->first.second]) {
                cur += it->second;
                matched[it->first.first] = true;
                matched[it->first.second] = true;
            }
        }
        bool ok = true;
        rep(i,0,n) {
            if (!matched[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            best = min(best, cur);
        }
    }
    if (best == DINF)
        cout << "impossible" << endl;
    else
        cout << best << endl;
    return 0;
}

