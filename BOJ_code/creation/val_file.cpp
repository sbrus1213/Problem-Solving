#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 50000, "n");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
        string file = inf.readString("[.a-z]{1,100}", "file");
    }
    inf.readEof();
}
