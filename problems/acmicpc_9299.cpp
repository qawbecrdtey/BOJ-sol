#include <stdio.h>
#include <vector>
int main() {
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        printf("Case %d: ", tt);
        int n;
        scanf("%d", &n);
        std::vector<int> v;
        for(int i = n; i >= 0; i--) {
            int x; scanf("%d", &x);
            v.push_back(x * i);
        } v.pop_back();
        int i = 0;
        while(!v[i]) i++;
        if(i == n) printf("0 0\n");
        else {
            printf("%d", n - i - 1);
            for(; i < v.size(); i++) {
                printf(" %d", v[i]);
            } printf("\n");
        }
    }
}