#include <cstdio>
int main() {
    int n, t = 0;
    while (scanf("%d", &n)) {
        if (!n)break;
        printf("Case %d: Sorting... done!\n", ++t);
        while (n--)scanf("%*d");
    }
}