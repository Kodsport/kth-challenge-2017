#include <iostream>
using namespace std;

typedef long long ll;

bool cancycle(ll odd, int veven) {
  ll round=(odd+1)&~(2ll);
  int vodd = __builtin_ctzll(round);
  return veven>vodd;
}

bool tiling(ll n, ll m) {
  int vn = __builtin_ctzll(n);
  int vm = __builtin_ctzll(m);
  if (vm == 1) return false;
  if (vn + vm <= 2) return false;
  if (vn >= 1 and vm >=2) return true;
  if (vn==0) return cancycle(n,vm);
  if (vm==0) return cancycle(m,vn);
  abort();
}

int main() {
  ll n,m;
  cin >> n >> m;
  cout << (tiling(n,m) ? "possible" : "impossible") << endl;  
}
