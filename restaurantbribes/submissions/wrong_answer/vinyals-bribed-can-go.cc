#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<pair<int,double>> VID;

double opt(double a, double b) {
  double mx=0;
  for (int x=1;x<=10;++x) {
    mx=max(mx,b*x-a*a*x*x);
  }
  return mx;
}

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  VVI g(n);
  for (int i=0;i<m;++i) {
    int a,b;
    cin >> a >> b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  VI isbribed(n);
  VID bribes(k);
  for (auto& x : bribes) {
    cin >> x.first >> x.second;
    x.first--;
    isbribed[x.first]=true;
  }
  VVI ng(n);
  for (int i=0;i<n;++i) {
    for (int v : g[i]) if (isbribed[v]) ng[i].push_back(v);
  }
  double ans=0;
  for (const auto& x : bribes) {
    double influence=0;
    for(int j : g[x.first]) {
      // Might need to sum in proper order...
      influence+=100./ng[j].size();
    }
    ans+=opt(x.second,influence);
  }
  printf("%.10f\n", ans);
}
