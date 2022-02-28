#include <algorithm>
#include <stdio.h>
int main() {
    int a[4]; for(auto &i : a) scanf("%d", &i);
    std::sort(a, a + 4); printf("%d", a[0] * a[2]);
}