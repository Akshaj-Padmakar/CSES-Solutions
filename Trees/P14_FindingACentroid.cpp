#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0, a, b; i + 1 < n; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> sz(n, 0), par(n, 0);
    function<void(int, int)> dfs=[&](int node, int p) {
        sz[node] = 1;
        par[node] = p;
        for(auto ch : g[node]) {
            if(ch ^ p) {
                dfs(ch, node);
                sz[node] += sz[ch];
            }
        }
    };

    dfs(0, -1);

    function<int(int, int)> dfs_centroid=[&](int node, int p) {
        for(auto ch : g[node]) {
            if(ch ^ p) {
                if(sz[ch] * 2 > n) {
                    return dfs_centroid(ch, node);
                }
            }
        }
        return node;
    };
    
    cout << dfs_centroid(0, -1) + 1 << '\n';
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