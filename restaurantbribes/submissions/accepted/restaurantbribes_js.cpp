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

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N, M, K;
	cin >> N >> M >> K;
	vector<vi> G(N);
	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vi bribers(N);
	vector<pair<int, double>> B(K);
	vi isbriber(N);
	rep(i,0,K) {
		cin >> B[i].first >> B[i].second;
		--B[i].first;
                isbriber[B[i].first]=true;
		trav(it, G[B[i].first]) bribers[it]++;
	}
	vector<double> TB(K);
	rep(i,0,K) {
		trav(it, G[B[i].first]) if (not isbriber[it]) TB[i] += 100.0 * 1000000 / bribers[it];
	}
	double res = 0;
	rep(i,0,K) {
		double a = B[i].second;
		double mx = 0;
		rep(l,0,11) {
			double ans = TB[i] / 1000000 * l - pow(l*a, 2);
			mx = max(ans, mx);
		}
		res += mx;
	}
	cout << setprecision(15) << fixed;
	cout << res << endl;
}
