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
    vector<bool> vis(n, false);
    function<void(int)> dfs=[&](int node) {
        vis[node] = 1;
        for(auto ch: g[node]) {
            if(!vis[ch]) {
                dfs(ch);
            }
        }
    };
    vector<int> root;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            root.push_back(i);
        }
    }
    cout << (int)root.size() - 1 << '\n';

    for(int i = 1; i < (int)root.size(); i++) {
        cout << root[0] + 1 << " " << root[i] + 1 << "\n";
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