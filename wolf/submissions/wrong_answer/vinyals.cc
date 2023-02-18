#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int my[4];
  memset(my,0,sizeof(my));
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
    int they=13-my[i];
    int notit=0;
    for (int j=0;j<4;++j) if (i!=j) notit+=my[j];
    if (they>notit) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}
