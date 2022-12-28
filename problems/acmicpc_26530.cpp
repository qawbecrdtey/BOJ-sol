#include <cstdio>
using namespace std;
int main() {
    int t; scanf("%d", &t); while(t--) {
        int n; scanf("%d\n", &n);
        long double sum = 0;
        while(n--) {
            long double x, d;
            scanf("%*s %Lf %Lf", &x, &d);
            sum += x * d;
        } printf("$%.2Lf\n", sum);
    }
}