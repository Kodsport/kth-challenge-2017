#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef tuple<double,int,int> edge;

template<typename T> ostream& operator << (ostream& o, const vector<T>& v) {
  for (const T& x : v) o << x << ' ';
  return o;
}

double sq(double x) { return x*x; }

struct pt {
  double x,y;
  double dist2(const pt& p) const { return sq(x-p.x)+sq(y-p.y); }
};

istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }

struct circle {
  pt c; double r;
  bool contains(const pt& p) const { return c.dist2(p)<=sq(r);; }
  bool intersects(const circle& o) const { return c.dist2(o.c)<=sq(r+o.r); }
  double dist(const circle& o) const { return sqrt(c.dist2(o.c))-r-o.r+200; }
};

istream& operator >> (istream& in, circle& c) { return in >> c.c >> c.r; }

bool traverse(const VVI& g) {
  VI seen(g.size());
  seen[0]=true;
  queue<int> q;
  q.push(0);
  int ret=1;
  while(not q.empty()) {
    const VI& x = g[q.front()];
    q.pop();
    for (int j : x) {
      if (seen[j]) continue;
      seen[j]=true;
      q.push(j);
      ret+=1;
    }
  }
  return (ret==g.size());
}

int main() {
  int n,m;
  double k;
  cin >> n >> m >> k;
  vector<circle> islands(n);
  vector<circle> palms(m);
  for (circle& i : islands) cin >> i;
  for (circle& p : palms) {
    cin >> p;
    p.r*=k;
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
        g[i].push_back(j);
        rg[j].push_back(i);
      }
    }
  }
  if (traverse(g) and traverse(rg)) {
    printf("0\n");
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
    VVI gg(g);
    VVI rgg(rg);
    if (not M[i][j]) {
      gg[i].push_back(j);
      rgg[j].push_back(i);
    }
    if (not M[j][i]) {
      rgg[i].push_back(j);
      gg[j].push_back(i);
    }
    if (traverse(gg) and traverse(rgg)) {
      printf("%.10f\n",d);
      return 0;
    }
  }
  printf("impossible\n");
}
