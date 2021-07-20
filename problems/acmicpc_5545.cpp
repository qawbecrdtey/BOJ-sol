#include <stdio.h>
#include <algorithm>
int main() {
    int n, dough_price, topping_price, dough_cal;
    scanf("%d%d%d%d", &n, &dough_price, &topping_price, &dough_cal);
    auto topping_cal = new int[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &topping_cal[i]);
    }
    std::sort(topping_cal, topping_cal + n, [](int a, int b) { return a > b; });
    long long x = dough_cal, y = dough_price;
    for(int i = 0; i < n; i++) {
        if((x + topping_cal[i]) * y <= x * (y + topping_price)) {
            printf("%lld", x / y);
            return 0;
        }
        x += topping_cal[i];
        y += topping_price;
    }
    printf("%lld", x / y);
}