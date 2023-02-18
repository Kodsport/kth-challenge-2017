#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef queue<int> QI;

const int N=20;
int all;

int n,m,l;
int limatrix[1<<N][N];
char limatrixsz[1<<N];
char dist[1<<N][N];
char reachable[N];
VVI g,switches;

void add(int mask, int r) {
  for (int s : switches[r]) {
    for (int i=0;i<n;++i) {
      if ((s&(1<<i))==0) continue;
      int& x = limatrix[mask][i];
      if (x) {
        s^=x;
      }
      else {
        x=s;
        limatrixsz[mask]++;
        break;
      }
    }
  }
}

void dfs(int u) {
  if (reachable[u]) return;
  reachable[u] = 1;
  for (int v : g[u]) dfs(v);
}

int bfs() {
  for (int r=0;r<n;++r) {
    if (reachable[r]) add(all,r);
  }
  int goal = limatrixsz[all];
  //cerr << "Goal: " << goal << endl;
  QI q;
  dist[2][1]=1;
  add(2,1);
  q.push(1);
  q.push(2);
  while (not q.empty()) {
    int r=q.front();q.pop();
    int mask=q.front();q.pop();
    //cerr << r << " " << mask << endl;
    for (int s : g[r]) {
      int nmask=mask|(1<<s);
      //cerr << "  " << s << " " << nmask << endl;
      char& x = dist[nmask][s];
      if (x!=-1) continue;
      x=dist[mask][r]+1;
      if (limatrixsz[nmask]==0) {
        limatrixsz[nmask]=limatrixsz[mask];
        memcpy(limatrix[nmask],limatrix[mask],N*sizeof(int));
        add(nmask,s);
      }
      if (s==0 and limatrixsz[nmask]==goal) return x;
      q.push(s);
      q.push(nmask);
    }
  }
  return -1;
}

int main() {
  memset(dist,-1,sizeof(dist));
  memset(limatrix,0,sizeof(limatrix));
  memset(limatrixsz,0,sizeof(limatrixsz));
  memset(reachable,0,sizeof(reachable));
  cin >> n >> m >> l;
  g.resize(n);
  for (int i=0;i<m;++i) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  all=0;
  for (int i=0;i<n;++i) all |= (reachable[i]<<i);
  //for (auto v : g) {for (auto x : v) cerr << x << ' '; cerr << endl;} cerr << endl;
  switches.resize(n);
  for (int i=0;i<l;++i) {
    int r,p;
    cin >> r >> p;
    int mask=0;
    for (int j=0;j<p;++j) {
      int x;
      cin >> x;
      mask|=(1<<x);
    }
    switches[r].push_back(mask);
  }
  cout << bfs() << endl;
}
