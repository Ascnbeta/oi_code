const int maxn = 1e7+20;
int minp[maxn],p[maxn],tot;
inline void eular(int x) {
    for (int i = 2; i <= x; i++) {
        if (!minp[i]) minp[i] = ++tot,p[tot] = i;
        for (int j = 1; i*p[j] <= x && j <= minp[i]; j++) {
            minp[i*p[j]] = j;
        }
    }
}