#include <stdio.h>
int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int x;
        scanf("%d", &x);
        printf("%d ", x);
        double a, b, c, d;
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        printf("%lf\n", a / (b + c) * d);
    }
}