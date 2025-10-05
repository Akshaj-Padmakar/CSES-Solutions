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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<int>> dis(n, vector<int>(n, INF));

    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for(int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int a, b;
        cin >> a >> b; a--, b--;
        cout << (dis[a][b] == INF ? -1 : dis[a][b]) << '\n';
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