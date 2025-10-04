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
    vector<int> a(n), b(m);
    for(auto &x: a) {
        cin >> x;
    }

    for(auto &x : b) {
        cin >> x;
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    // dp[i][j] -> max LIS for a[0..i] and b[0..j]

    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));

    dp[0][0] = (a[0] == b[0]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1] : 0) + 1;
                par[i][j] = {i - 1, j - 1};
                continue;
            } else {
                dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1] : 0);
                par[i][j] = {i - 1, j - 1};
            }

            if(i) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(dp[i][j] == dp[i-1][j]) {
                    par[i][j] = {i - 1, j};
                }
            }

            if(j) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(dp[i][j] == dp[i][j - 1]) {
                    par[i][j] = {i, j - 1};
                }
            }
        }
    }

    cout << dp[n-1][m-1] << '\n';
    pair<int, int> cur = {n-1, m-1};
    vector<int> ans;
    while(1){
        debug(cur);
        if(a[cur.first] == b[cur.second]) {
            ans.push_back(a[cur.first]);
        }
        cur = par[cur.first][cur.second];

        if(cur.first < 0 || cur.second < 0) {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &x: ans) {
        cout << x << ' ';
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