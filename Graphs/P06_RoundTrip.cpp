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
    vector<int> par(n, -1);
    vector<bool> vis(n, false);
    int start = -1, end = -1;
    function<bool(int, int)> dfs=[&](int node, int p) {
        par[node] = p;
        vis[node] = 1;

        for(auto ch : g[node]) {
            if(ch ^ p) {
                if(vis[ch]) {
                    end = ch;
                    start = node;
                    return true;
                } else {
                    if(dfs(ch, node)) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    bool ans = false;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            ans |= dfs(i, -1);
            if(ans) {
                break;
            }
        }
    }
    if(!ans) {
        cout << "IMPOSSIBLE\n"; return;
    }
    int cur = start;
    vector<int> cycle;
    while(true) {
        cycle.push_back(cur);
        if(cur == end) {
            break;
        }
        cur = par[cur];
    }
    cycle.push_back(start);
    
    cout << cycle.size() << '\n';
    for(auto &x: cycle) {
        cout << x + 1 << ' ';
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