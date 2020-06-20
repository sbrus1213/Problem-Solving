#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <utility>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, half;
pair<ll, int> arr[200001];
pair<ll, int> real[200001];
const ll mod = 1e9 + 7;
vector<pair<ll, int>> seg;

pair<ll, int> query(int l, int r) {
    l += half;
    r += half;
    pair<ll, int> ret;
    while (l <= r) {
        if (l % 2) {
            ret.first = (ret.first + seg[l].first);
            ret.second += seg[l++].second;
        }
        if (!(r % 2)) {
            ret.first = (ret.first + seg[r].first);
            ret.second += seg[r--].second;
        }
        l >>= 1;
        r >>= 1;
    }
    return ret;
}

void update(int idx, ll x) {
    idx += half;
    seg[idx].first = x;
    seg[idx].second++;
    while (idx /= 2) {
        seg[idx].first = (seg[idx * 2].first + seg[idx * 2 + 1].first);
        seg[idx].second = seg[idx * 2].second + seg[idx * 2 + 1].second;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].first++;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        real[arr[i].second] = { arr[i].first,i };
    }


    for (half = 1; half < n; half <<= 1);
    seg.resize(half * 2);
    ll ans = 1;
    update(real[0].second, real[0].first);
    for (int i = 1; i < n; i++) {
        pair<ll, ll> t1 = query(0, real[i].second - 1), t2 = query(real[i].second + 1, n - 1);
        ll l = (real[i].first * t1.second) % mod;
        l = (l - t1.first) % mod;
        ll r = t2.first % mod;
        r = (r - (real[i].first * t2.second) % mod) % mod;
        ll tmp = (l + r) % mod;
        ans = (ans * tmp) % mod;
        update(real[i].second, real[i].first);
    }
    cout << ans;
}