#include <cmath>
#include <cstdio>
#include <cstdint>
constexpr int M = 1000000;
struct s {
	int arr[M + 1];
	constexpr s() : arr() {
		arr[0] = 1;
		for(int i = 1; i <= M; i++) {
			arr[i] = ((arr[(int)floorl(i - sqrtl(i))] + arr[(int)floorl(logl(i))]) % M + arr[(int)floorl(i * sinl(i) * sinl(i))]) % M;
		}
	}
};
int main() {
	s st;
	int n;
	while(true) {
		scanf("%d", &n);
		if(n == -1) break;
		printf("%d\n", st.arr[n]);
	}
}