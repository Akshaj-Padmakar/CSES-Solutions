#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int log2_ceil(int n) {
    int x = 0;
    while ((1ll << x) < (int)(n)) {
        x++;
    }
    return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree(int n) {
        _n = n;
        log = log2_ceil(_n);
        size = 1 << log;
        d = vector<S>(2 * size, e());
    }

    segtree(const vector<S>& v) {
        _n = v.size();
        log = log2_ceil(_n);
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
    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
private:
    int _n, size, log;
    vector<S> d;

    void update(int k) {
        d[k] = op(d[2 * k], d[2 * k + 1]);
    }
};

const int MOD = 1e9 + 7;
int op(int a, int b) { return (a + b) % MOD; }
int e() { return 0; }



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(auto &x: a) {
        cin >> x;
        mp[x]++;
    }


    int id = 0;
    for(auto &x: mp) {
        x.second = id++;
    }

    for(int i = 0; i < n; i++) {
        a[i] = mp[a[i]];
    }

    segtree<int, op, e> st(n + 1);
    // st[i] -> number of ways to end the Increasing sequence with value i.
    for(int i = 0; i < n; i++) {
        int sm = st.prod(0, a[i]);
        st.set(a[i], st.get(a[i]) + sm + 1);
    }

    cout << st.prod(0, n + 1) << '\n';
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