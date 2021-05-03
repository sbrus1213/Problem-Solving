#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    registerGen(argc, argv, 1);

    // # of people
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int m = atoi(argv[3]);
    
    cout << n << ' ' << k << ' ' << m << '\n';
}
