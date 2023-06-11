#include <cassert>
#include <cstdio>
int main() {
    int n; scanf("%d", &n);
    int diffarr[123456]{};
    for(int i = 0; i < n; i++) {
        int y, m; scanf("%d-%d", &y, &m);
        int val = y * 12 + m - 1; // val / 12 = y, val % 12 + 1 = m
        diffarr[val]++;
        scanf("%d-%d", &y, &m);
        val = y * 12 + m - 1;
        diffarr[val + 1]--;
    }
    int day = 0, cnt = 0, cur = 0;
    for(int i = 1; i < 123456; i++) {
        cur += diffarr[i];
        assert(cur >= 0);
        if(cur > cnt) {
            day = i;
            cnt = cur;
        }
    }
    printf("%d-%02d", day / 12, day % 12 + 1);
}