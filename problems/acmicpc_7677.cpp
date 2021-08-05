#include <stdio.h>
constexpr int M = 10000;
void mul(int const A[4], int const B[4], int C[4]) {
    C[0] = ((A[0] * B[0]) % M + (A[1] * B[2]) % M) % M;
    C[1] = ((A[0] * B[1]) % M + (A[1] * B[3]) % M) % M;
    C[2] = ((A[2] * B[0]) % M + (A[3] * B[2]) % M) % M;
    C[3] = ((A[2] * B[1]) % M + (A[3] * B[3]) % M) % M;
}
void power(int A[4], int n) {
    if(!n) {
        A[0] = A[3] = 1;
        A[1] = A[2] = 0;
        return;
    }
    if(n == 1) {
        A[0] = A[1] = A[2] = 1;
        A[3] = 0;
        return;
    }
    int B[4], C[4];
    power(B, n >> 1);
    mul(B, B, C);
    power(B, n & 1);
    mul(B, C, A);
}
int main() {
    int A[4], n;
    while(true) {
        scanf("%d", &n);
        if(n == -1) return 0;
        power(A, n);
        printf("%d\n", A[1] % M);
    }
}