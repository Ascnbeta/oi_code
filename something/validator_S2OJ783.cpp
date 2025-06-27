#include "D:/toolchains/testlib.h"
#include <iostream>
using namespace std;
int father[50004];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p=find(x),q=find(y);
    if (p == q) return;
    father[p] = q;
}
int maxn = 0;
bool connect() {
    int tmp = find(1);
    for (int i = 2; i <= maxn; i++) {
        if (find(i) != tmp) return false;
    }
    return true;
}
int t[100000];
int main (void) {
    freopen("D:/codes/exe/a.in","r",stdin);
    registerValidation();
    int n=inf.readInt(1,5000);inf.readSpace();int m=inf.readInt(1,100000);inf.readEoln();
    for (int i = 1; i <= 50000; i++) father[i]=i;
    
    for(int i=1;i<=m;i++) {
        int x=inf.readInt(1,50000);inf.readSpace();
        int y=inf.readInt(1,50000);inf.readSpace();
        maxn = max(maxn,max(x,y));
        int w=inf.readInt(0,15000);inf.readEoln();
        merge(x,y);
    }
    ensuref(connect(),"The graph is disconnected.");
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = inf.readInt(1,50000);inf.readSpace();
        tot += cnt;ensuref(tot<=maxn,"The amount of cities is incorrect.");
        for (int j = 1; j < cnt; j++) {
            int x= inf.readInt(1,maxn);inf.readSpace();
            ensuref(!t[x],"One city can only belong to one province.");
            t[x] = i;
        }
        int x= inf.readInt(1,maxn);inf.readEoln();
        ensuref(!t[x],"One city can only belong to one province.");
    }
    for (int i = 1; i < n; i++) {
        int cnt = inf.readInt(0,100);inf.readSpace();
    }
    inf.readInt(0,100);inf.readEoln();
    inf.readInt(1,maxn);inf.readSpace();inf.readInt(1,maxn);inf.readEoln();
    inf.readEof();
    return 0;

}