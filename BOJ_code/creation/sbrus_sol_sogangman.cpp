#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> t(n);
    for (ll& ti : t) cin >> ti;
    sort(t.begin(), t.end());

    ll ans = 0;
    if (n % 2) ans = t.back();
    for (int i = 0, j = (n % 2 ? n - 2 : n - 1); i < j; i++, j--)
        ans = max(ans, t[i] + t[j]);
    cout << ans;
}