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
    int n;
    cin >> n;
    if(n == 1) {
        cout << "01\n";return;
    }
    int tot = 1ll<<(n-1);
    vector<vector<pair<int, int>>> g(tot);
    int id = 0;
    for(int i = 0; i < tot; i++) {
        int nxt0 = (i*2 + 0) % tot;
        int nxt1 = (i*2 + 1) % tot;
        g[i].push_back({nxt0, id++});
        g[i].push_back({nxt1, id++});
    }
    vector<int> vis(1ll<<n, 0);
    vector<int> ans;
    function<void(int)> dfs=[&](int node) {
        while(g[node].size()) {
            auto [ch, idd] = g[node].back();
            g[node].pop_back();
            if(vis[idd]) {
                continue;
            }
            vis[idd] = true;
            dfs(ch);
            ans.push_back(ch % 2);
        }
    };
    dfs(0);
    reverse(ans.begin(), ans.end());

    string fans(n-1, '0');
    for(auto &x : ans) {
        fans.push_back('0' + x);
    }

    cout << fans << '\n';
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