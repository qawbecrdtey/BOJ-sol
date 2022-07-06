#include <cmath>
#include <cstdio>
int main() {
    long double d;
    scanf("%Lf", &d);
    printf("%.7Lf", 4 * sqrtl(d));
}