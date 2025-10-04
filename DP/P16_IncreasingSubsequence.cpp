#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

    //read dilworth theorem.
    //the size of the longest chain equals the minimum number of antichains needed to cover the set.

    // int n;
    // cin >> n;
    // vector<int> v(n);

    // for(auto &x: v) {
    //     cin >> x;
    // }

    // set<int> s;

    // for(int i = 0; i < n; i++) {
    //     auto it = s.lower_bound(v[i]);
    //     if(it != s.end()) {
    //         s.erase(it);
    //     }
    //     s.insert(v[i]);
    // }
    // cout << s.size() << '\n';

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (int)(n)) x++;
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree(int n) {
        _n = n;
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<S>(2 * size, e());
    }

    segtree(const vector<S>& v) {
        _n = v.size();
        log = ceil_pow2(_n);
        size = 1 << log;
        d = vector<S>(2 * size, e());

        for (int i = 0; i < _n; i++) {
            d[size + i] = v[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);

        p += size; d[p] = x;

        for (int i = 1; i <= log; i++) {
            update(p >> i);
        }
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
private:
    int _n, size, log;
    vector<S> d;

    void update(int k) {
        d[k] = op(d[2 * k], d[2 * k + 1]);
    }
};

int op(int a, int b) { return max(a, b); }
int e() { return 0; }


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(auto &x: a) {
        cin >> x;
        mp[x] = 1;
    }

    int id = 0;
    for(auto v : mp) {
        mp[v.first] = id++;
    }

    for(auto &x: a) {
        x = mp[x];
    }

    segtree<int, op, e> stdp(n);

    for(int i = 0; i < n; i++) {
        int v = stdp.prod(0, a[i]);
        stdp.set(a[i], max(stdp.get(a[i]), v + 1));
    }

    cout << stdp.prod(0, n) << '\n';

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