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
    queue<int> q;
    int n, k;
    cin >> n >> k;
    int x, a, b, c;
    cin >> x >> a >> b >> c;

    int prev = x;
    q.push(prev);
    
    int sm = prev;
    for(int i = 1; i < k; i++) {
        int nxt = (a*prev + b)% c;
        q.push(nxt);
        prev = nxt;
        sm += prev;
    }
    int cur = k;
    int fans = 0;
    while(cur <= n) {
        fans ^= sm;
        int front = q.front();
        sm -= front;
        q.pop();
        
        int nxt = (a * prev + b) % c;
        q.push(nxt);
        
        sm += nxt;
        prev = nxt;
        
        cur++;
    }
    cout << fans << '\n';
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