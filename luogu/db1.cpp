#include <bits/stdc++.h>
using namespace std;
int n[300];
int g(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main () {
    for (int i = 1; i <= 400000000; i++) {
        int s = g(i);
        if (n[s] == 0 && s != i) n[s] = i;
    }
    for (int i = 1; i <= 100; i++) {
        printf("%d: %d\n",i,n[i]);
    }
    return 0;
}