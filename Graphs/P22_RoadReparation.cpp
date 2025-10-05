#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

struct dsu {
public:
        dsu(int n) {
            _n = n;
            par.assign(n, 0);
            sz.assign(n, 1);
            for(int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        int find(int node) { // find the root of this compenent.
            if(node == par[node]) {
                return node;
            }

            return par[node] = find(par[node]);
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if(a == b) {
                return;
            }

            if(sz[a] < sz[b]) {
                swap(a, b);
            }

            par[b] = a;
            sz[a] += sz[b];
        }

        int size(int a) {
            int pa = find(a);
            return sz[pa];
        }

        bool same(int a, int b) {
            return find(a) == find(b);
        }
private:
    int _n;
    vector<int> par, sz;
};


bool cmp(array<int, 3> a, array<int, 3> b) {
    return a[2] < b[2];
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        e.push_back({a, b, c});
    }
    sort(e.begin(), e.end(), cmp);
    dsu ds(n);
    int ans = 0;
    for(auto [a, b, c] : e) {
        if(ds.same(a, b)) {
            continue;
        }
        ans += c;
        ds.merge(a, b);
    }
    for(int i = 0; i < n; i++) {
        if(!ds.same(i, 0)) {
            cout << "IMPOSSIBLE\n"; return;
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    // cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}