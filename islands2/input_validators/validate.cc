#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double sq(double x) { return x*x; }
const double EPS=1e-6;
bool LE(double a, double b) { return b-a < EPS; }
bool LT(double a, double b) { return b-a <-EPS; }
bool EQ(double a, double b) { return fabs(b-a) < EPS; }

struct pt {
  double x,y;
  pt operator - (const pt& p) const { return pt({x-p.x,y-p.y}); }
  double operator * (const pt& p) const { return x*p.x + y*p.y; }
  double mod2() const { return (*this)*(*this); }
};
struct circle {
  pt c; double r;
  bool inside(const pt& p) const {
    double d2 = (c-p).mod2();
    double r2=sq(r);
    return LT(r2,d2);
  }
  bool touch(const circle& c) const {
    double d2 = (c.c-this->c).mod2();
    double r2 = sq(c.r+r);
    return LE(r2,d2);
  }
  bool tangent(const circle& c) const {
    double d2 = (c.c-this->c).mod2();
    double R2 = sq(c.r+r);
    return EQ(R2,d2);
  }
};


int main() {
  int n,m; double k;
  if (!(cin >> n >> m >> k)) return 43;
  vector<circle> v(n);
  for (auto& x : v) cin >> x.c.x >> x.c.y >> x.r;
  for (int i=0;i<n;++i) {
    for (int j=i+1;j<n;++j) {
      if (v[i].touch(v[j])) {
		  cerr << "island " << i << " touches " << j << endl;
		  return 43;
	  }
    }
  }
  vector<circle> w(m);
  for (auto& x : w) {
    cin >> x.c.x >> x.c.y >> x.r;
    x.r*=k;
  }
  for (const auto& x : w) {
    bool inland=false;
    for (const auto& y : v) {
      if (y.inside(x.c)) inland=true;
      else if(x.tangent(y)) {
		  cerr << "palm " << x.c.x << " " << x.c.y << " " << x.r << " tangent island " << y.c.x << " " << y.c.y << " " << y.r << endl;
		  return 43;
	  }
    }
    if (not inland) {
		cerr << "palm " << x.c.x << " " << x.c.y << " not inside" << endl;
		return 43;
	}
  }
  return 42;
}
