#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    registerGen(argc, argv, 1);

    // # of people
    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));

    int k = rnd.next(1, n);
    int m = rnd.next(1, n);
    
    cout << n << ' ' << k << ' ' << m << '\n';
}
