#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, l;
    cin >> n >> k >> l;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (min(a, min(b, c)) < l) continue;
        if (a + b + c < k) continue;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
    }
    cout << ans.size() / 3 << '\n';
    for (int x : ans) cout << x << ' ';
}