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

    // # of kinds of file extention
    int m = rnd.next(1, n);

    vector<string> ext;

    for (int i = 0; i < m; i++) {
        ext.push_back(rnd.next("[a-z]{1,98}"));
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        string ext_ = rnd.any(ext);
        int esz = ext_.length();
        cout << rnd.next("[a-z]{1," + to_string(99 - esz) + "}") << "." << ext_ << '\n';
    }
}
