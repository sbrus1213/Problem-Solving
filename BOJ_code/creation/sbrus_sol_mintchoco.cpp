#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int mxn = 100100;

int cnt[mxn];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int x, i = 1, op = 1;
    cin >> x;

    for (int i = 0; i < n; i++) {
        char _;
        if (i) {
            cin >> _;
            op = (_ == '*' ? 1 : -1);
            cin >> x;
        }
        if (!x) return cout << "mint chocolate", 0;
        for (int p = 2; p * p <= x; p++) {
            while (x % p == 0) {
                cnt[p] += op;
                x /= p;
            }
        }
        if (x > 1) cnt[x] += op;
    }

    if (*min_element(cnt, cnt + mxn) < 0)
        cout << "toothpaste";
    else
        cout << "mint chocolate";
}