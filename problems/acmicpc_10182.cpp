#include <cmath>
#include <cstdio>
int main() {
    int t; scanf("%d", &t); while(t--) {
        char a[3]; long double d;
        scanf("%s = %Lf", a, &d);
        if(*a == 'H') printf("%.2Lf\n", -log10l(d));
        else printf("%.2Lf\n", 14 + log10l(d));
    }
}