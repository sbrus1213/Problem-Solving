#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    registerGen(argc, argv, 1);

    // # of file names
    int n = rnd.next(atoi(argv[1]), atoi(argv[2]));

    vector<string> ext;

    for (int i = 0; i < n; i++) {
        ext.push_back(rnd.next("[a-z]{98}"));
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << rnd.next("[a-z]{1}") << "." << ext[i] << '\n';
    }
}
