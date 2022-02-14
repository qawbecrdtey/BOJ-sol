#include <cmath>
#include <cstdio>
inline bool f(int broken, int n) {
    if(!n) return !(broken & 1);
    while(n) {
        int x = n % 10;
        if(broken & (1 << x)) return false;
        n /= 10;
    } return true;
}
inline int len(int n) {
    if(!n) return 1;
    int res = 0;
    while(n) {
        n /= 10;
        res++;
    } return res;
}
inline int min(int a, int b) { return a > b ? b : a; }
int main() {
    int n, m, broken = 0;
    scanf("%d%d", &n, &m);
    while(m--) {
        int x; scanf("%d", &x);
        broken |= (1 << x);
    }
    int ans = abs(n - 100);
    for(int i = n; i >= 0 && n - i < ans; i--) {
        if(f(broken, i)) {
            ans = min(ans, n - i + len(i));
            break;
        }
    }
    for(int i = n; i - n < ans; i++) {
        if(f(broken, i)) {
            ans = min(ans, i - n + len(i));
            break;
        }
    }
    printf("%d", ans);
}