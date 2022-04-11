#include <algorithm>
#include <cstdio>
int main() {
    int a[3]; scanf("%d%d%d", a, a + 1, a + 2);
    std::sort(a, a + 3);
    printf("%d", (((a[0] == a[1] && a[1] == a[2]) << 1) | (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])));
}