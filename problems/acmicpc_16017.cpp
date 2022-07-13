#include <cstdio>
int main() {
    int a[4]; scanf("%d%d%d%d", a, a + 1, a + 2, a + 3);
    if((*a == 8 || *a == 9) && (a[1] == a[2]) && (a[3] == 8 || a[3] == 9)) {
        printf("ignore");
    } else printf("answer");
}