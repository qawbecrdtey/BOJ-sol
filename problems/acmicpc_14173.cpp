#include <algorithm>
#include <cstdio>
int main() {
    int a[8]; for(int &i : a) scanf("%d", &i);
    int const x = std::max(std::max(a[2], a[6]) - std::min(a[0], a[4]), std::max(a[3], a[7]) - std::min(a[1], a[5]));
    printf("%d", x * x);
}