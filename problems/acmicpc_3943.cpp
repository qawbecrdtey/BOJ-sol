#include <stdio.h>
#include <map>
using namespace std;
int dp(map<int, int> &m, int x) {
    if(m.find(x) != m.end()) return m[x];
    if(x == 1) return m[1] = 1;
    if(x & 1) return m[x] = max(x, dp(m, x * 3 + 1));
    return m[x] = max(x, dp(m, x / 2));
}
int main() {
    map<int, int> m;
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp(m, n));
    }
}