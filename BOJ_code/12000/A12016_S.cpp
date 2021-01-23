// BOJ 12016 라운드 로빈스케줄러
// Segment tree & priority queue

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ll long long

struct Seg {
    int half;
    vector<int> item;
    Seg(int n_) {
        for (half = 1; half <= n_; half <<= 1);
        item = vector<int>(half << 1);
    }
    void init() {
        // TODO
    }
    int sum(int l, int r) {
        int res = 0;
        l += half, r += half;
        while (l <= r) {
            if (l % 2) res += item[l++];
            if (!(r % 2)) res += item[r--];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void update(int i, int x) {
        i += half;
        item[i] = x;
        while (i >>= 1) {
            item[i] = item[i << 1] + item[i << 1 | 1];
        }
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(pii(x, i));
    }

    Seg seg(n);
    ll prvp = 0, prvid = -1, rem = n, time = 0;
    vector<ll> ans(n);
    while (!pq.empty()) {
        ll p = pq.top().first, id = pq.top().second;
        pq.pop();

        if (prvp == p) {
            ll t = seg.sum(prvid + 1, id);
            time += id - prvid - 1 - t;
            prvid = id;

            ans[id] = ++time;

            rem--;
            seg.update(id, 1);
        }
        else {
            ll t;
            if (prvid != -1) {
                t = seg.sum(prvid + 1, n - 1);
                time += n - prvid - 1 - t;
            }
            prvid = -1;

            time += (p - prvp - 1) * rem;
            prvp = p;

            t = seg.sum(prvid + 1, id);
            time += id - prvid - 1 - t;
            prvid = id;

            ans[id] = ++time;

            rem--;
            seg.update(id, 1);
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}