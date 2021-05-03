// BOJ 16713 Generic Queries
// prefix sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1), ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = ps[i - 1] ^ a[i];
    }

    int ans = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        ans ^= ps[r] ^ ps[l - 1];
    }

    cout << ans;

    return 0;
}