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
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    map<int, int> mp;
    set<pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        if(st.find({mp[cur], -cur}) != st.end()) {
            st.erase(st.find({mp[cur], -cur}));
        }
        mp[cur]++;
        st.insert({mp[cur], -cur});

        if(i >= k) {
            int front = a[i-k];
            st.erase(st.find({mp[front], -front}));
            mp[front]--;
            if(mp[front] > 0) {
                st.insert({mp[front], -front});
            }
        }

        if(i >= k - 1) { // we have a window of k length
            cout << -(*(--st.end())).second << ' ';
        }

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