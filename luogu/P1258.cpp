#include <bits/stdc++.h>
using namespace std;
double s,a,b;
int main () {
    cin >> s >> a >> b;
    double tmp = (b + a) * s / (b + 3 * a);
    printf("%.6f",tmp / b + (s - tmp) / a);
    return 0;
}