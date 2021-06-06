#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> v;
	auto a = new int[k];
	for(int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
	}
	int res = 0;
	for(int i = 0; i < k; i++) {
		bool flag = false;
		for(auto now : v) {
			if(a[i] == now) { flag = true; break; }
		}
		if(flag) continue;
		if(v.size() < n) {
			v.push_back(a[i]);
			continue;
		}
		int max = 0;
		int maxi = 0;
		for(int j = 0; j < v.size(); j++) {
			int cnt = i + 1;
			while(cnt < k) {
				if(a[cnt] == v[j]) break;
				cnt++;
			}
			if(max < cnt) {
				max = cnt;
				maxi = j;
			}
		}
		v[maxi] = a[i];
		res++;
	}
	printf("%d", res);
	delete[] a;
}