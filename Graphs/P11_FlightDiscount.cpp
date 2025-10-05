#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e15;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n), rg(n);
    vector<array<int, 3>> e;
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
        rg[b].push_back({a, c});

        e.push_back({a, b, c});
    }

    auto dijkstra=[](int root, vector<int> &dis, vector<vector<pair<int, int>>> &gg) {
        dis[root] = 0;
        set<pair<int,int>> q; // dis node
        q.insert({0, root});

        while(q.size()) {
            auto [d, node] = *q.begin();
            q.erase(q.begin());
            if(dis[node] < d) {
                continue;
            }

            for(auto [ch, w]: gg[node]) {
                if(dis[ch] > d + w) {
                    dis[ch] = d + w;
                    q.insert({dis[ch], ch});
                }
            }
        }
    };

    vector<int> dis0(n, INF), disN(n, INF);
    dijkstra(0, dis0, g);
    dijkstra(n - 1, disN, rg);

    int ans = dis0[n-1];
    for(auto [a, b, c] : e) {
        ans = min(ans, dis0[a] + c/2 + disN[b]);
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