#include <iostream>
#include <vector>
using namespace std;
void f(vector<vector<int>> &v, long unsigned int *d, int now) {
	if(d[now] == v.size() || v[d[now]][0] != now) return;
	auto &vec = v[d[now]];
	d[now]++;
	for(auto val : vec) {
		f(v, d, val);
		cout << val << ' ';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int*[n + 1];
	for(int i = 1; i <= n; i++) {
		a[i] = new int[n + 1];
		int sum = 0;
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		if(sum & 1) {
			cout << -1;
			return 0;
		}
	}
	vector<vector<int>> v;
	auto d = new unsigned long[n + 1];
	for(int i = 1; i <= n; i++) {
		d[i] = v.size();
		for(int j = i + 1; j <= n; j++) {
			while(a[i][j]) {
				int now = j, prev = i;
				vector<int> vec = { i };
				while(now != i) {
					vec.push_back(now);
					a[prev][now]--; a[now][prev]--;
					for(int k = i; k <= n; k++) {
						if(k == now) continue;
						if(a[now][k]) {
							prev = now;
							now = k;
							break;
						}
					}
				}
				a[prev][now]--; a[now][prev]--;
				v.push_back(move(vec));
			}
		}
	}
	f(v, d, 1);
	cout << 1;
}