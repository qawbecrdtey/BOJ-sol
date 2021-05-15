#include <stdio.h>
#include <vector>
using namespace std;
void prime(int n, vector<int> &v) {
	auto a = new bool[n + 1]();
	for(int i = 2; i <= n; i++) {
		if(!a[i]) v.push_back(i);
		for(int j = 2; i * j <= n; j++) {
			a[i * j] = true;
		}
	}
	delete[] a;
}
int main() {
	vector<int> p;
	int n;
	scanf("%d",&n);
	prime(n, p);
	int l = 0, r = 0;
	int sum = 0;
	int cnt = 0;
	while(r <= p.size()) {
		if(l == r) { if(r == p.size()) break; sum = p[r++]; continue; }
		if(sum < n) { if(r == p.size()) break; sum += p[r++]; continue; }
		if(sum > n) { sum -= p[l++]; continue; }
		cnt++; if(r == p.size()) break; sum += p[r++];
	}
	printf("%d", cnt);
}