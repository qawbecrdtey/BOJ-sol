#include <cstdio>
int main() {
    int a[3][6];
    for(auto &i : a) {
        for(int &j : i) {
            scanf("%d", &j);
        }
        i[5] -= i[2];
        i[4] -= i[1];
        i[3] -= i[0];
        if(i[5] < 0) i[5] += 60, i[4]--;
        if(i[4] < 0) i[4] += 60, i[3]--;
        if(i[3] < 0) i[3] += 60;
        printf("%d %d %d\n", i[3], i[4], i[5]);
    }

}