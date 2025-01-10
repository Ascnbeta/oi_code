#include <bits/stdc++.h>
using namespace std;
int mp,p,f,l,n;
double score,ds;
int main (){
    cin >> mp >> p >> f >> l;
    n = mp + p + f + l;
    ds = 1.0 * 1e7 / n;
    score += mp;
    score += (mp+p)*ds;
    score += 0.5*f*ds;
    int sc = score;
    if (sc >= 9900000) {
        cout << "EX+";
    }else if (sc >= 9800000 && sc < 9900000) {
        cout << "EX";
    }else if (sc >= 9500000 && sc < 9800000) {
        cout << "AA";
    }else if (sc >= 9200000 && sc < 9500000) {
        cout << "A";
    }else if (sc >= 8900000 && sc < 9200000) {
        cout << "B";
    }else if (sc >= 8600000 && sc < 8900000) {
        cout << "C";
    }else {
        cout << "D";
    }
    return 0;
}