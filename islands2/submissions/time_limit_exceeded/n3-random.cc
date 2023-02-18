#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef tuple<double,int,int> edge;

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

int traverse(const VVI& g, VI& seen, int start) {
  seen[start]=true;
  queue<int> q;
  q.push(start);
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
  return ret;
}

int seed;
bool get_helpful(const VVI& g, VI& seen, VI& helpful) {
  int n=g.size();
  seen.assign(n,false);
  int start = seed%n;
  int nseen=traverse(g,seen,start);
  if (nseen==n) {
    helpful.assign(n,true);
    return true;
  }
  helpful.assign(n,false);
  for (int i=0;i<n;++i) {
    int ii=(i+start)%n;
    if (seen[ii]) continue;
    VI xseen(seen);
    int extra = traverse(g,xseen,ii);
    if (nseen+extra==n) helpful[ii]=true;
  }
  return false;
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

  VI seen,helpful,rseen,rhelpful;
  seed=rand();
  bool ook = get_helpful(g,seen,helpful);
  bool rook = get_helpful(rg,rseen,rhelpful);

  if (ook and rook) {
    cout << 0 << endl;
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
    if (((seen[i] and helpful[j]) or (seen[j] and helpful[i])) and
        ((rseen[i] and rhelpful[j]) or (rseen[j] and rhelpful[i]))) {
      printf("%.10f\n",d);
      return 0;
    }
  }
  printf("impossible\n");
}
