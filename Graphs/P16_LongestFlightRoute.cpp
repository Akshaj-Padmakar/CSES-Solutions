#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    vector<int> in(n, 0);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        rg[b].push_back(a);
        in[b]++;
    }
    queue<int> q;
    vector<int> tp;
    for(int i = 0; i < n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int node = q.front(); q.pop();
        tp.push_back(node);
        
        for(auto &ch: g[node]) {
            in[ch]--;
            if(in[ch] == 0) {
                q.push(ch);
            }
        }
    }

    vector<int> dp(n, -INF), par(n, -1);
    for(auto node : tp) {
        if(node == 0) {
            dp[node] = 0;
        }
        for(auto prev : rg[node]) {
            if(dp[node] < dp[prev] + 1) {
                dp[node] = dp[prev] + 1;
                par[node] = prev;
            }
        }
    }
    int cur = n - 1;
    vector<int> ans;
    while(true) {
        ans.push_back(cur);
        cur = par[cur];
        if(cur == -1) {
            break;
        }
    }
    if(ans.back() != 0) {
        cout << "IMPOSSIBLE\n"; return;
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto &x: ans) {
        cout << x + 1 << " ";
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