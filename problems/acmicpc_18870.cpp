#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new int[n];
	set<int> s;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(s.find(a[i]) == s.end()) s.insert(a[i]);
	}
	auto b = new int[s.size()];
	auto it = s.begin();
	for(int i = 0; i < s.size(); i++) {
		b[i] = *it; ++it;
	}
	sort(b, b + s.size());
	for(int i = 0; i < n; i++) {
		printf("%ld ", lower_bound(b, b + s.size(), a[i]) - b);
	}
	delete[] a;
}