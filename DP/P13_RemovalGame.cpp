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
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    vector<int> psm = a;
    for(int i = 1; i < n; i++) {
        psm[i] += psm[i - 1];
    }

    auto sm=[&](int i, int j) {
        return psm[j] - (i > 0 ?  psm[i-1] : 0);
    };


    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] -> playing on the subarray of a[i..j], stores the max score the starting player can score.

    for(int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for(int j = 0; j < n; j++) {
        for(int i = n - 1; i >= 0; i--) {
            if(i >= j) {
                continue;
            }

            dp[i][j] = max(a[i] + sm(i + 1, j) - dp[i + 1][j], a[j] + sm(i, j - 1) - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << '\n';
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