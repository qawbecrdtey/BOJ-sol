#include <algorithm>
#include <stdio.h>
int main() {
    int a, b;
    int arr[4];
    while(scanf("%d%d", &a, &b) == 2) {
        arr[0] = b;
        arr[1] = a + 1 - b;
        if(arr[1] > arr[0]) std::swap(arr[0], arr[1]);
        if(arr[0] % 2) arr[2] = arr[0] + 1;
        else arr[2] = arr[0] - 1;
        arr[3] = a + 1 - arr[2];
        std::sort(arr, arr + 4);
        for(auto now : arr) {
            if(now != b) printf("%d ", now);
        } printf("\n");
    }
}