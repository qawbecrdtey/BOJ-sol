#include <stdio.h>
#include <vector>
using namespace std;
void prime(vector<int> &p) {
	auto b = new bool[1000000]();
	for(int i = 2; i < 1000000; i++) {
		if(!b[i]) {
			p.push_back(i);
			for(int j = i; j < 1000000; j += i) {
				b[j] = true;
			}
		}
	}
	delete[] b;
}
int main() {
	vector<int> pr;
	prime(pr);
	while(true) {
		int n;
		scanf("%d", &n);
		if(n == 0) return 0;
		for(auto p : pr) {
			if(*lower_bound(pr.begin(), pr.end(), n - p) == n - p) {
				printf("%d = %d + %d\n", n, p, n - p);
				break;
			}
		}
	}
}