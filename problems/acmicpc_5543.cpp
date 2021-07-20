#include <stdio.h>
int main() {
    int a[3], b[2];
    for(auto &i : a) scanf("%d", &i);
    for(auto &i : b) scanf("%d", &i);
    int min = 1000000;
    for(auto i : a) {
        for(auto j : b) {
            if(min > i + j) min = i + j;
        }
    }
    printf("%d", min - 50);
}