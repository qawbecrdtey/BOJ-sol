#include <cstdio>
int main() {
    int a[6], sum = 0; for(int &i : a) scanf("%d", &i);
    for(int i = 1; i < 6; i++) sum += (a[i] == a[0]);
    printf("%d", sum);
}