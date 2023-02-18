#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

const int N=101;
ll binom[N][N];
void mkbinoms() {
  binom[0][0]=1;
  for (int i=1;i<N;++i) {
    binom[i][0]=binom[i][i]=1;
    for (int j=1;j<i;++j) {
      binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%MOD;
    }
  }
}

ll range(int n, int base) {
  ll ret=0;
  for (int i=0;i<=n;++i) {
    ret+=binom[n][i]*(base+i);
  }
  return ret;
}

ll s(ll x) {
  if (x==0) return 0;
  int leftmostone=63-__builtin_clzll(x);
  int rightmostone=__builtin_ffsll(x)-1;
  if (leftmostone==rightmostone) {
    return (rightmostone+s(x-1)) % MOD;
  }
  else {
    ll y = x^(1ll<<rightmostone);
    int middlezeros=leftmostone-rightmostone+1-__builtin_popcountll(x);
    //cerr << x << ' ' << leftmostone << ' ' << rightmostone << ' ' << nextone << ' ' << middlezeros << endl;
    return (s(y)+range(rightmostone,leftmostone+middlezeros+2)) % MOD;
  }
}

int main() {
  mkbinoms();
  ll a,b;
  cin >> a >> b;
  cout << (s(b) + MOD - s(a-1)) % MOD << endl;
}
