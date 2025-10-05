#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e6;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0, a, b; i < m; i++) {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    vector<int> dis(n, INF), par(n, -1);

    q.push(0);
    dis[0] = 0;
    while(q.size()) {
        int node = q.front(); q.pop();
        for(auto ch : g[node]) {
            if(dis[ch] > dis[node] + 1) {
                dis[ch] = dis[node] + 1;
                par[ch] = node;
                q.push(ch);
            }
        }
    }

    if(dis[n-1] == INF) {
        cout << "IMPOSSIBLE\n"; return;
    }

    cout << dis[n-1] + 1 << '\n';

    int cur = n - 1;
    
    vector<int> ans;
    while(cur >= 0) {
        ans.push_back(cur);
        cur = par[cur];
    }
    reverse(ans.begin(), ans.end());
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