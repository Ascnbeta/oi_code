#include "testlib.h"
using namespace std;
int main (void) {
    registerValidation();
    int n=inf.readInt(1,100000);
    inf.readEoln();
    for(int i=1;i<n;i++) {
        inf.readInt(1,100000);
        inf.readSpace();
    }
    inf.readInt(1,100000);
    inf.readEoln();
    inf.readEof();
    return 0;

}