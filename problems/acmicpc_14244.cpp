#include <cstdio>
using namespace std;
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i < m; i++) {
        printf("%d %d\n", i - 1, m - 1);
    }
    for(int i = m - 1; i < n - 1; i++) {
        printf("%d %d\n", i, i + 1);
    }
}