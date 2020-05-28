// BOJ 11399 ATM
// greedy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n; cin >> n;

    vector<int> time(n);
    for (int& x : time) cin >> x;
    sort(time.begin(), time.end());

    int tot = 0, ans = 0;
    for (int x : time) {
        tot += x;
        ans += tot;
    }
    cout << ans;
}