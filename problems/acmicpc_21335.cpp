#include <cmath>
#include <cstdio>
int main() {
    long double x;
    scanf("%Lf", &x);
    printf("%Lf", sqrtl(x / M_PIl) * M_PIl * 2);
}