#include <iostream>
int main() {
    long long a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    printf((d - a) * (d - a) + (e - b) * (e - b) < (c + f) * (c + f) ? "YES" : "NO");
}