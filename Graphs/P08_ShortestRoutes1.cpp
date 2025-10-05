#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 1e16;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
    }
    vector<int> dis(n, INF);
    set<pair<int, int>> st;    // dis, node;

    st.insert({0, 0});
    dis[0] = 0;
    while(st.size()) {
        auto [d, node] = *st.begin();
        st.erase(st.begin());
        if(dis[node] < d) {
            continue;
        }

        for(auto [ch, w] : g[node]) {
            if(dis[ch] > d + w) {
                dis[ch] = d + w;
                st.insert({dis[ch], ch});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << dis[i] << " ";
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