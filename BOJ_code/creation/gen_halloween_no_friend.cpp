#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    registerGen(argc, argv, 1);

    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));
    int m = 0;
    int k = rnd.next(1, min(n, 3000));

    int candy[30030];
    for (int i = 1; i <= n; ++i)
        candy[i] = rnd.next(1, 10000);

    cout << n << ' ' << m << ' ' << k << '\n';

    cout << candy[1];
    for (int i = 2; i <= n; ++i) cout << ' ' << candy[i];
    cout << '\n';
}
