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
	
	rep(c,0,14) 
	rep(d,0,14) 
	rep(h,0,14) 
	rep(s,0,14) {
		// Assume I have at least half of the cards
		if (c + d + h + s >= 26) {
			vi me = {c, d, h, s};
			vi ot(4);
			rep(i,0,4) ot[i] = 13-me[i];

			cout << "I have:";
			rep(i,0,4) cout << " " << me[i];
			cout << endl << "other have:";
			rep(i,0,4) cout << " " << ot[i];
			cout << endl;
			rep(subset,0,1<<4) {
				int ns = 0;
				int has = 0;
				rep(j,0,4) {
					if ((subset & (1 << j)) && ot[j]) {
						has += ot[j];
						ns |= ((1<<4) - 1)&~(1 << j);
					}
				}
				int ng = 0;
				rep(j,0,4) {
					if (ns & (1 << j)) {
						ng += me[j];
					}
				}
				cout << "has " << has << " ng " << ng << endl;
				assert(has <= ng);
			}
		}
	}
}
