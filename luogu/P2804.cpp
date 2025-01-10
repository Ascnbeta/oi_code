#include <bits/stdc++.h>
using namespace std;
const int mod = 92084931;
int n,m,ans;
int a[200004],b[200004],c[200004];
void msort(int l,int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    msort(l,mid);
    msort(mid+1,r);
    int i = l,j = mid + 1,p = l;
    while(i <= mid && j <= r) {
        if (b[i] >= b[j]) {
            c[p++] = b[i];
            ++i; 
        }else{
            ans += mid - i + 1;
            ans %= mod;
            c[p++] = b[j];
            ++j;
        }
    }
    while (i <= mid) c[p++] = b[i],i += 1;
    while (j <= r) c[p++] = b[j],j += 1;
    for (int k = l; k <= r; k++) {
        b[k] = c[k];
    }
    return;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x - m;
        b[i] = b[i-1] + a[i];
    }
    msort(0,n);
    cout << ans % mod << endl;
    return 0;
}