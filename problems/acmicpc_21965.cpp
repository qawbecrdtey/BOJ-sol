#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a = 0, b;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        scanf("%d", &b);
        if(a < b && !flag) goto END;
        if(a > b && flag) goto END;
        if(a > b && !flag) { flag = true; goto END; }
        printf("NO");
        return 0;
        END:
        a = b;
    }
    printf("YES");
}