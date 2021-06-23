#include <stdio.h>
#include <algorithm>
int main() {
    int n, k, c;
    scanf("%d%d%d", &n, &k, &c);
    auto a = new int[k + 2];
    a[0] = 0;
    for(int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
    }
    a[k + 1] = n;
    std::sort(a, a + k + 2);
    int l = 0, r = n;
    int resm = n, rescnt = 1;
    while(l < r) {
        auto const m = (l + r) / 2;
        int cur = 0;
        int cnt = 0;

        for(int i = 1; i < k + 2; i++) {
            if(a[i] - a[i - 1] > m) goto F;
            if(a[i] - a[cur] > m) {
                if(i - 1 == cur) goto F;
                cur = i - 1;
                cnt++;
            }
        }
        if(cnt > c) goto F;
        r = resm = m;
        rescnt = cnt;
        continue;
        F:
        l = m + 1;
    }
    printf("%d ", resm);
    if(rescnt < c) printf("%d", a[1]);
    else {
        int cur = k + 1;
        for (int i = k; i >= 0; i--) {
            if (a[cur] - a[i] > resm) {
                cur = i + 1;
            }
        }
        printf("%d", a[cur]);
    }
}