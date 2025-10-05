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
const int MOD = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
    }

    set<pair<int, int>> st; // dis, node
    vector<int> dis(n, INF), dpMX(n, 0), dpMN(n, m + 5), cnt(n, 0);
    dis[0] = 0;
    dpMX[0] = 0;
    dpMN[0] = 0;
    cnt[0] = 1;

    st.insert({0, 0});
    while(st.size()) {
        auto [d, node] = *st.begin();
        st.erase(st.begin());
        if(d > dis[node]) {
            continue;
        }
        
        for(auto [ch, w] : g[node]) {
            if(dis[ch] > dis[node] + w) {
                dis[ch] = dis[node] + w;
                cnt[ch] = cnt[node];
                dpMX[ch] = dpMX[node] + 1;
                dpMN[ch] = dpMN[node] + 1;
                st.insert({dis[ch], ch});
            } else if (dis[ch] == dis[node] + w) {
                dpMX[ch] = max(dpMX[ch], dpMX[node] + 1);
                dpMN[ch] = min(dpMN[ch], dpMN[node] + 1);
                cnt[ch] += cnt[node];
                cnt[ch] %= MOD;
            }
        }
    }

    cout << dis[n-1] << " " << cnt[n-1] << " " << dpMN[n-1] << " " << dpMX[n-1] << '\n';
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