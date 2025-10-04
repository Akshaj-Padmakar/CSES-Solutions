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
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    queue<int> q;
    int cur = -1, ans = 0, xr = 0;
    for(int i = 0; i < n; i++) {
        int nxt = cur == -1 ? x : ((cur * a + b) % c);
        xr ^= nxt;

        if(i >= k) {
            int front = q.front();
            q.pop();
            xr ^= front;
        }
        q.push(nxt);

        if(i >= k - 1) {
            ans ^= xr;
        }
        swap(nxt, cur);
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