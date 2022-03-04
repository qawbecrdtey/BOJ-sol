#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k; cin >> n >> k;
	auto arr = new pair<int, int>[n];
	auto bag = new int[k];
	for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	for(int i = 0; i < k; i++) cin >> bag[i];
	sort(arr, arr + n);
	sort(bag, bag + k);
	int idx = 0;
	priority_queue<int> pq;
	long long res = 0;
	for(int i = 0; i < k; i++) {
		while(idx < n && arr[idx].first <= bag[i]) pq.push(arr[idx++].second);
		if(pq.empty()) continue;
		res += pq.top(); pq.pop();
	}
	cout << res;
}