#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

const int mxn = 30030;

int par[mxn];
int candy[mxn];

int find(int i) {
    if (par[i] < 0) return i;
    return par[i] = find(par[i]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    candy[x] += candy[y];
    par[x] += par[y];
    par[y] = x;
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        cin >> candy[i];

    fill(par, par + mxn, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    vector<pii> dump;
    for (int i = 1; i <= n; ++i)
        if (par[i] < 0)
            dump.push_back(pii(-par[i], candy[i]));

    int sz = dump.size();
    vector<vector<int> > dp(sz + 1, vector<int>(k + 1));
    for (int i = 1; i <= sz; ++i) {
        int cost = dump[i - 1].first, value = dump[i - 1].second;
        for (int j = 0; j <= k; ++j) {
            if (j < cost) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + value);
        }
    }

    cout << dp[sz][k];
}