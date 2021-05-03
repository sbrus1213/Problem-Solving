#include "testlib.h"
using namespace std;
using pii = pair<int, int>;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 30000, "n");
    inf.readSpace();
    int m = inf.readInt(0, 100000, "m");
    inf.readSpace();
    int mnk = min(n, 3000);
    int k = inf.readInt(1, mnk, "k");
    inf.readEoln();

    inf.readInt(1, 10000, "a[0]");
    for(int i = 1; i < n; ++i) {
        inf.readSpace();
        inf.readInt(1, 10000, "a[" + to_string(i) + "]");
    }
    inf.readEoln();

    set<pii> st;
    for(int i = 0;i < m;++i) {
        int x, y;
        x = inf.readInt(1, n, "x");
        inf.readSpace();
        y = inf.readInt(1, n, "y");
        inf.readEoln();
        ensure(x != y);
        if(x > y) swap(x, y);
        st.insert(pii(x, y));
    }
    ensure(st.size() == m);

    inf.readEof();
}
