#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int C[500][500];

int search(vi &comp, int at, int tobeat) {
    while (at < comp.size() && comp[at] == -1) ++at;
    if (at == comp.size()) return 0;
    if (tobeat <= 0) return 1<<30;
    int ans = 1<<30;
    for (int match = at+1; match < comp.size(); ++match)
        if (comp[match] != -1) {
            int save = comp[match];
            comp[match] = -1;
            int sub_beat = min(ans, tobeat) - C[comp[at]][save];
            ans = min(ans, C[comp[at]][save] + search(comp, at+1, sub_beat));
            comp[match] = save;
        }
    return ans;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(C, -1, sizeof(C));
    for (int i = 0; i < m; ++i) {
        int p, q, c;
        scanf("%d%d%d", &p, &q, &c);
        C[p-1][q-1] = C[q-1][p-1] = c;
    }
    vector<vi> comps;
    for (int i = 0; i < n; ++i) {
        vi comp = {i};
        for (int j = 0; j < n; ++j)
            if (C[i][j] != -1) comp.push_back(j);
        if (comp.size() > 1 && comp[1] < i) continue;
        if (comp.size() % 2) {
            printf("impossible\n");
            return 0;
        }
        comps.push_back(comp);
    }
    int ans = 0;
    for (auto &comp: comps) {
        //        printf("search ");
        //        for (auto j: comp) printf(" %d", j);
        //        printf(" cur ans %d\n", ans);
        random_shuffle(comp.begin(), comp.end());
        ans += search(comp, 0, 1<<30);
    }
    printf("%d\n", ans);
}
