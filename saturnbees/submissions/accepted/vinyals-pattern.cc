#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int N=10000;
const int M=10000;

char seen[N][M];

ll n,m;

template<bool iodd>
void canonical(int& i, int& j) ;

template<>
void canonical<true>(int& i, int& j) {
  if (i<0) {
    i+=n;
    j-=1;
  }
  else if (i>=n) {
    i-=n;
    j+=1;
  }
  j+=m;
  j%=m;
}

template<>
void canonical<false>(int& i, int& j) {
  if (j<0) {
    j+=m;
    i-=1;
  }
  else if (j>=m) {
    j-=m;
    i+=1;
  }
  i+=n;
  i%=n;
}

template<bool iodd>
bool set(int i, int j) {
  canonical<iodd>(i,j);
  //cerr << i << ' ' << j << endl;
  return seen[i][j]++;
}

template<bool iodd>
bool cancycle(int jshift) {
  memset(seen,0,sizeof(seen));
  int i=0,j=0,it=0;
  do {
    if (set<iodd>(i,j)) return false;
    if (set<iodd>(i,j+1)) return false;
    if (set<iodd>(i,j-1)) return false;
    if (set<iodd>(i+1,j)) return false;
    if (set<iodd>(i-1,j)) return false;
    if (set<iodd>(i-1,j+1)) return false;
    if (set<iodd>(i-1,j-1)) return false;
    if (set<iodd>(i-2,j)) return false;
    i+=2;
    j+=jshift;
    canonical<iodd>(i,j);
    ++it;
  } while (i!=0 or j!=0);
  return (m*n%(it*8)==0);
}

bool tiling() {
  int vn = __builtin_ctzll(n);
  int vm = __builtin_ctzll(m);
  if (vm == 1) return false;
  if (vn + vm <= 2) return false;
  if (vn >= 1 and vm >=2) return true;
  if (vn==0) return cancycle<true>(2) or cancycle<true>(-2);
  if (vm==0) return cancycle<false>(2) or cancycle<false>(-2);
  abort();
}

int main() {
  cin >> n >> m;
  cout << (tiling() ? "possible" : "impossible") << endl;  
}
