#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e14;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e;
    vector<vector<int>> g(n);
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        e.push_back({a, b, -c});
        g[a].push_back(b);
    }
    
    vector<int> dis(n, INF);
    dis[0] = 0;
    for(int i = 0; i < n - 1; i++) {
        for(auto [a, b, c] : e) {
            if(dis[a] != INF) {
                dis[b] = min(dis[b], dis[a] + c);
            }
        }
    }
    
    vector<int> vis(n, false);
    function<void(int)> dfs=[&](int node) {
        vis[node] = true;
        for(auto ch : g[node]) {
            if(!vis[ch]) {
                dfs(ch);
            }
        }
    };

    for(auto [a, b, c] : e) {
        if(dis[b] > dis[a] + c && dis[a] != INF) {
            dfs(b);
            if(vis[n-1]) {
                cout << -1 << '\n'; return;
            }
        }
    }

    cout << -dis[n-1] << '\n';
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