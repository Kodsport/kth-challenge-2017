#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int C[300][300];
int iters = 0;
const int BREAK = 1<<24;

int search(vi &comp, int at, int tobeat) {
    if (++iters > BREAK) return tobeat;
    while (at < comp.size() && comp[at] == -1) ++at;
    if (at == comp.size()) return 0;
    if (tobeat <= 0) return tobeat;
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

int greedy(vi comp, vi &outcomp) {
    int ans = 0;
    while (comp.size() > 2) {
        int bi = 0, bj = 1, bk = 2, bl = 3;
        for (int i = 0; i < comp.size(); ++i)
            for (int j = i+1; j < comp.size(); ++j)
                for (int k = i+1; k < comp.size(); ++k) {
                    if (k == j) continue;
                    for (int l = k+1; l < comp.size(); ++l) {
                        if (l == j) continue;
                        if (C[comp[i]][comp[j]] + C[comp[k]][comp[l]] <
                            C[comp[bi]][comp[bj]] + C[comp[bk]][comp[bl]])
                            bi = i, bj = j, bk = k, bl = l;
                    }
                }
        if (C[comp[bi]][comp[bj]] > C[comp[bk]][comp[bl]]) {
            swap(bi, bk);
            swap(bj, bl);
        }
        ans += C[comp[bi]][comp[bj]];
        outcomp.push_back(comp[bi]);
        outcomp.push_back(comp[bj]);
        comp.erase(comp.begin() + bj);
        comp.erase(comp.begin() + bi);
    }
    if (comp.size()) {
        assert(comp.size() == 2);
        ans += C[comp[0]][comp[1]];
        outcomp.push_back(comp[0]);
        outcomp.push_back(comp[1]);
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
        vi ncomp;
        int g = greedy(comp, ncomp);
        g = min(g, search(ncomp, 0, g));
        fprintf(stderr, "comp sz %d greedy %d\n", comp.size(), g);
        for (int i = 0; i < 10; ++i) {
            iters = 0;
            random_shuffle(comp.begin(), comp.end());
            g = min(g, search(comp, 0, g));
        }
        ans += g;
    }
    printf("%d\n", ans);
}
