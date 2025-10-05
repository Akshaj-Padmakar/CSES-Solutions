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
    vector<vector<char>> a(n, vector<char>(m));
    for(auto &x: a) {
        for(auto &y : x) {
            cin >> y;
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, false));
    vector<pair<int, int>> dr = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    auto is_valid=[&](int x, int y) {
        return x>=0 && x < n && y >= 0 && y < m && vis[x][y] == false && a[x][y] == '.';
    };

    function<void(int, int)> dfs=[&](int x, int y) {
        vis[x][y] = true;
        for(auto [dx, dy] : dr) {
            int nx = dx + x, ny = dy + y;
            if(is_valid(nx, ny)) {
                dfs(nx, ny);
            }
        }
    };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(is_valid(i, j)) {
                dfs(i, j);
                ans++;
            }
        }
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