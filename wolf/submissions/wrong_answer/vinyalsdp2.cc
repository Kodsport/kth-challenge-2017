#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> VI;
VI they;

int my[4];
int dp[14][14][14][14];

bool can(int a, int b, int c, int d) {
  cerr << a << ' ' << b << ' ' << c << ' ' << d << endl;
  int& x = dp[a][b][c][d];
  if(x!=-1) return x;
  int idx=my[0]-a+my[1]-b+my[2]-c+my[3]-d;
  if (idx>=they.size()) return x=(a+b+c+d);
  int what=they[idx];
  if (what!=0 and a>0 and can(a-1,b,c,d)) return x=1;
  if (what!=1 and b>0 and can(a,b-1,c,d)) return x=1;
  if (what!=2 and c>0 and can(a,b,c-1,d)) return x=1;
  if (what!=3 and d>0 and can(a,b,c,d-1)) return x=1;
  return x=0;
}

int main() {
  memset(my,0,sizeof(my));
  memset(dp,-1,sizeof(dp));
  int n;
  cin >> n;
  for (int i=0;i<n;++i) {
    int dummy; char c;
    cin >> dummy >> c;
    switch(c) {
    case 'C':
      ++my[0];
      break;
    case 'D':
      ++my[1];
      break;
    case 'H':
      ++my[2];
      break;
    case 'S':
      ++my[3];
      break;
    }
  }
  for (int i=0;i<4;++i) {
    for (int j=my[i];j<13;++j) they.push_back(i);
  }
  cerr << they.size() << endl;
  cout << (can(my[0],my[1],my[2],my[3]) ? "Possible" : "Impossible") << endl;
}
