#include <algorithm>
#include <cstdio>
using std::copy;
constexpr int M = 100;
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
    if(n == 1) return;
    int B[4], C[4]; copy(A, A + 4, B);
    power(B, n >> 1);
    mul(B, B, C);
    copy(A, A + 4, B);
    power(B, n & 1);
    mul(C, B, A);
}
int main() {
    int x, y, a, b, n;
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &n);
    int A[4] { x, y, 1, 0 };
    power(A, n);
    printf("%02d", (A[2] * b + A[3] * a) % M);
}