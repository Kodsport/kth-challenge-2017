#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	double k;
	cin >> n >> m >> k;
	vector<vector<bool>> cansee(n, vector<bool>(n));
	vector<double> x(n), y(n), r(n);
	rep(i,0,n) {
		cin >> x[i] >> y[i] >> r[i];
	}
	rep(i,0,m) {
		double px, py, h;
		cin >> px >> py >> h;
		h *= k;
	
		int ti = -1;
		rep(j,0,n) {
			double dx = px - x[j];
			double dy = py - y[j];
			if (dx * dx + dy * dy <= r[j] * r[j]) ti = j;
		}
		rep(j,0,n) {
			double dx = px - x[j];
			double dy = py - y[j];
			if (dx * dx + dy * dy <= (h + r[j]) * (h + r[j])) {
				cansee[ti][j] = true;
			}
		}
	}
	vector<vi> G(n), G2(n);
	rep(i,0,n) rep(j,0,n) {
		if (i == j) continue;
		if (cansee[i][j]) {
			G[i].push_back(j);
			G2[j].push_back(i);
		}
	}
	int leaves = 0;
	int roots = 0;
	scc(G, [&](vi& v) {
		bool isroot = true;
		bool isleaf = true;
		trav(it, v) {
			trav(it2, G[it]) {
				if (comp[it2] != comp[it]) isleaf = false;
			}
			trav(it2, G2[it]) {
				if (comp[it2] == -1) isroot = false;
			}
		}
		leaves += isleaf;
		roots += isroot;
	});
        if (ncomps == 1 ) cout << "0" << endl;
	else if ((leaves == 1 && roots == 1) || ncomps == 2) {
		double ans = 1e18;
		rep(i,0,n) {
			rep(j,0,n) {
				if (i != j && comp[i] == 0 && comp[j] == ncomps - 1) {
					double dx = x[i] - x[j];
					double dy = y[i] - y[j];
					ans = min(ans, sqrt(dx*dx + dy*dy) - r[i] - r[j]+200);
				}
			}
		}
		cout << fixed << setprecision(10) << ans << endl;
	} else cout << "Impossible" << endl;
}
