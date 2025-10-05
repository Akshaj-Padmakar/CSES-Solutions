#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n, false), col(n, false);
    function<bool(int, bool)> dfs=[&](int node, bool c) {
        vis[node] = 1;
        col[node] = c;
        for(auto ch : g[node]) {
            if(vis[ch]) {
                if(col[ch] == col[node]) {
                    return false;
                }
            } else {
                if(!dfs(ch, c ^ 1)) {
                    return false;
                }
            }
        }
        return true;
    };
    bool ans = true;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            ans &= dfs(i, 0);
        }
    }
    if(!ans) {
        cout << "IMPOSSIBLE\n"; return;
    }

    for(int i = 0; i < n; i++) {
        cout << (col[i] ? 2 : 1) << ' ';
    }
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