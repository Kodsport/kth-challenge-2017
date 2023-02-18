#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int f(int x) {
  int ret;
  for (ret=0;x>1;++ret) {
    if (x&1) x+=1;
    else x>>=1;
  }
  return ret;
}

int main() {
  ll a,b;
  cin >> a >> b;
  ll s=0;
  for (ll i=a;i<=b;++i) {
    s+=f(i);
    s%=MOD;
  }
  cout << s << endl;
}
