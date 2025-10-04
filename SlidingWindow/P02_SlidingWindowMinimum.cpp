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
    deque<pair<int, int>> dq; // montanic min queue

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int cur = -1, ans = 0;
    for(int i = 0; i < n; i++) {
        int nxt = cur == -1 ? x : ((a*cur + b) % c);

        while(dq.size() && dq.back().first >= nxt) {
            dq.pop_back();
        }
        dq.push_back({nxt, i});

        while(dq.size() && dq.front().second <= i-k) {
            dq.pop_front();
        }

        if(i >= k - 1) {
            ans ^= dq.front().first;
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