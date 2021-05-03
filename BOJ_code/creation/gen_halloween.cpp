#include "testlib.h"
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
using pii = pair<int, int>;

bool isp[100100];
vector<int> prime;
int psz;

void getPrime() {
    isp[0] = isp[1] = 1;
    for (int i = 2; i < 100000; ++i) {
        if (isp[i]) continue;
        for (int j = i * 2; j < 100000; j += i) {
            isp[j] = 1;
        }
    }

    for (int i = 0; i < 100000; ++i) {
        if (!isp[i]) prime.push_back(i);
    }

    psz = prime.size();
}

vector<int> psum;

void getPsum(int n) {
    int sum = 0;
    psum.push_back(sum);
    for (int i = n - 1; i; --i) {
        sum += i;
        psum.push_back(sum);
    }
}

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    registerGen(argc, argv, 1);

    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));
    int m = rnd.next(0, min(100000, n * (n - 1) / 2));
    int k = rnd.next(1, min(n, 3000));

    getPrime();
    getPsum(n);

    int candy[30030];
    for (int i = 1; i <= n; ++i)
        candy[i] = rnd.next(1, 10000);

    int itv = prime[rnd.next(1, psz) - 1];
    int mx = (n - 1) * n / 2;
    vector<int> dummyNum;
    if (m) 
        for (int i = 0, x = rnd.next(0, mx - 1); i < m; ++i, x = (x + itv) % mx)
            dummyNum.push_back(x + 1);
    shuffle(dummyNum.begin(), dummyNum.end());

    vector<pii> vec;
    for (int x : dummyNum) {
        int u = lower_bound(psum.begin(), psum.end(), x) - psum.begin();
        int v = x - psum[u - 1];
        vec.push_back(pii(u, u + v));
    }
    shuffle(vec.begin(), vec.end());

    cout << n << ' ' << m << ' ' << k << '\n';

    cout << candy[1];
    for (int i = 2; i <= n; ++i) cout << ' ' << candy[i];
    cout << '\n';

    for (auto &it : vec) cout << it.first << ' ' << it.second << '\n';
}
