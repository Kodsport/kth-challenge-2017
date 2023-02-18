#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
#include <stack>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef tuple<double,int,int> edge;
typedef stack<int> SI;

template<typename T> ostream& operator << (ostream& o, const vector<T>& v) {
  for (const T& x : v) o << x << ' ';
  return o;
}

ll sq(double x) { return x*x; }

struct pt {
  ll x,y;
  ll dist2(const pt& p) const { return sq(x-p.x)+sq(y-p.y); }
};

istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }

struct circle {
  pt c; double r;
  bool contains(const pt& p) const { return c.dist2(p)<=sq(r);; }
  bool intersects(const circle& o) const { return c.dist2(o.c)<=sq(r+o.r); }
  double dist(const circle& o) const { return sqrt(c.dist2(o.c))-r-o.r+200; }
};

istream& operator >> (istream& in, circle& c) { return in >> c.c >> c.r; }

void dfs1(const VVI& g, int u, SI& out, VI& seen) {
  if (seen[u]) return;
  seen[u]=true;
  for (int v : g[u]) dfs1(g,v,out,seen);
  out.push(u);
}

void dfs2(const VVI& g, int u, int comp, VI& out) {
  if (out[u]!=-1) return;
  out[u] = comp;
  for (int v : g[u]) dfs2(g,v,comp,out);
}

VI scc(const VVI& g, const VVI& rg) {
  int n=g.size();
  VI seen(n);
  SI order;
  for (int i=0;i<n;++i) dfs1(g,i,order,seen);
  VI out(n,-1);
  while(not order.empty()) {
    dfs2(rg, order.top(), order.top(), out);
    order.pop();
  }
  return out;
}

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<circle> islands(n);
  vector<circle> palms(m);
  for (circle& i : islands) cin >> i;
  for (circle& p : palms) {
    cin >> p;
    p.r*=k;
    --p.r; // off by one
  }

  VVI M(n,VI(n));
  for (const circle& p : palms) {
    int src;
    VI dest(n);
    for (int i=0;i<n;++i) {
      const circle& is = islands[i];
      if (is.contains(p.c)) src=i;
      else if (is.intersects(p)) dest[i]=1;
    }
    for (int i=0;i<n;++i) M[src][i]+=dest[i];
  }
  VVI g(n), rg(n);
  for (int i=0;i<n;++i) {
    for (int j=0;j<n;++j) {
      if (M[i][j]) {
        //cerr << "edge " << i << ' ' << j << endl;
        g[i].push_back(j);
        rg[j].push_back(i);
      }
    }
  }

  VI component = scc(g,rg);
  VI parents(n,-1), children(n,-1);
  for (int i=0;i<n;++i) {
    parents[component[i]]=children[component[i]]=0;
  }
  for (int i=0;i<n;++i) {
    for (int j : g[i]) {
      if (component[i]==component[j]) continue;
      children[component[i]]++;
      parents[component[j]]++;
    }
  }
  VI extremal;
  for (int i=0;i<n;++i) {
    if (component[i]!=i) continue;
    if (parents[i]==0 or children[i]==0) extremal.push_back(i);
  }

  if (extremal.size()==1) {
    cout << 0 << endl;
    return 0;
  }
  if (extremal.size()>2) {
    cout << "impossible" << endl;
    return 0;
  }

  vector<edge> bridges;
  for (int i=0;i<n;++i) {
    for (int j=0;j<i;++j) {
      bridges.push_back(make_tuple(islands[i].dist(islands[j]),i,j));
    }
  }
  sort(bridges.begin(), bridges.end());

  for (const edge& b : bridges) {
    double d;
    int i,j;
    tie(d,i,j)=b;
    if ((component[i]==extremal[0] and component[j]==extremal[1]) or
        (component[i]==extremal[1] and component[j]==extremal[0])) {
      printf("%.10f\n",d);
      return 0;
    }
  }
  abort();
}
