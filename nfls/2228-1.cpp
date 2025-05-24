#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%d%d%d",&a,&b,&c);
    if (a>=0&&b>=0) {
        if (a>b) puts(">");
        else if (a==b) puts("=");
        else puts("<");
    }else if(a<0&&b<0) {
        if (c%2==0) {
            if (a>b) puts("<");
            else if (a==b) puts("=");
            else puts(">");
        }else{
            if (a>b) puts(">");
            else if (a==b) puts("=");
            else puts("<");
        }
    }else if(a>=0&&b<0) {
        if (c%2==0) {
            b=-b;
            if (a>b) puts(">");
            else if (a==b) puts("=");
            else puts("<");
        }else{
            puts(">");
        }
    }else if(a<0&&b>=0) {
        if (c%2==0) {
            a=-a;
            if (a>b) puts(">");
            else if (a==b) puts("=");
            else puts("<");
        }else{
            puts("<");
        }
    }
    return 0;
}