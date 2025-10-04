#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int INF = 5e3 + 5;
void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, INF));
    // dp[i][j] -> change s[0..i] to t[0..j]

    if(s[0] == t[0]) {
        dp[0][0] = 0;
    } else {
        dp[0][0] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + j == 0) {
                continue;
            }

            if(s[i] == t[j]) {
                dp[i][j] = i > 0 && j > 0 ? dp[i-1][j-1] : max(i, j);
            } else {
                dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1] : max(i, j)) + 1;
            }

            if(i) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if(j) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }

    cout << dp[n-1][m-1] << '\n';
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