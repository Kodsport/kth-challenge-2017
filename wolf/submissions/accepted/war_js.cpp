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

int ts(char c) {
	switch (c) {
		case 'H': return 0;
		case 'D': return 1;
		case 'C': return 2;
		case 'S': return 3;
	}
	assert(false);
}

bool can(int used, vector<int> cnts) {
	rep(i,0,1<<4) {
		int op = 0;
		rep(j,0,4) {
			if (i&(1<<j)) {
				op += 13 - cnts[j];
				if (j == used) --op;
			}
		}
		int me = 0;
		rep(j,0,4) {
			if (i&(~(1<<j))) {
				me += cnts[j];
				if (j == used) --op;
			}
		}
		if (op > me) {
			return false;
		}
	}
	return true;
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N;
	cin >> N;
	if (N > 26) {
		cout << "Possible" << endl;
	} else if (N == 26) {
		vector<int> cnts(4);
		vector<set<int>> has(4);
		rep(i,0,N) {
			int w;
			char c;
			cin >> w >> c;
			int s = ts(c);
			cnts[s]++;
			has[s].insert(w);
		}
		rep(i,0,4) {
			if (!has[i].empty() && sz(has[i]) != 13 && sz(has[i]) != *has[i].rbegin()) {
				if (can(i, cnts)) {
					cout << "Possible" << endl;
					return 0;
				}
			}
		}
		cout << "Impossible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
}
