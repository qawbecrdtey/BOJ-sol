#include <stdio.h>
#include <vector>
using namespace std;
int sqrt(int n) {
	int l = 0, r = n;
	int res = 1;
	if(n == 1) return 1;
	while(l < r) {
		int m = (l + r) / 2;
		if((long long)m * m == n) return m;
		if((long long)m * m <= n) {
			res = m;
			l = m + 1;
		}
		else r = m;
	}
	return res;
}
void prime(int n, vector<int> &p) {
	int sq = sqrt(n);
	auto b = new bool[sq + 1]();
	for(int i = 2; i <= sq; i++) {
		if(!b[i]) {
			p.push_back(i);
			for(int j = i; j <= sq; j += i) {
				b[j] = true;
			}
		}
	}
	delete[] b;
}
long long power(long long p, int n) {
	if(n == 0) return 1;
	if(n == 1) return p;
	auto const r = power(p, n / 2);
	return r * r * power(p, n % 2);
}
int main() {
	vector<int> input;
	int max = 0;
	while(true) {
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		input.push_back(n);
		if(max < n) max = n;
	}
	vector<int> pr;
	prime(max, pr);
	for(auto n : input) {
		long long res = 1;
		if(n == 1) {
			printf("0\n");
			continue;
		}
		for(auto p : pr) {
			int cnt = 0;
			while(n % p == 0) {
				n /= p;
				cnt++;
			}
			if(cnt == 0) continue;
			res *= (p - 1) * power(p, cnt - 1);
		}
		if(n > 1) {
			res *= n - 1;
		}
		printf("%lld\n", res);
	}
}