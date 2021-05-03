#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 3000, "n");
    inf.readSpace();

    int k = inf.readInt(1, n, "k");
    inf.readSpace();

    int m = inf.readInt(1, n, "m");
    
    inf.readEoln();
    
    inf.readEof();
}
