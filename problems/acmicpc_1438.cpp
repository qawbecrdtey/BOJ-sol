#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	auto a = new pair<int, int>[n];
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		x.push_back(a[i].first);
		y.push_back(a[i].second);
	}
	sort(a, a + n);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vector<int> xx, yy;
	for (int i = 0; i < x.size(); i++) {
		while (i < x.size() - 1 && x[i] == x[i + 1]) i++;
		xx.push_back(x[i]);
	}
	for (int i = 0; i < y.size(); i++) {
		while (i < y.size() - 1 && y[i] == y[i + 1]) i++;
		yy.push_back(y[i]);
	}
	auto const xx_size = xx.size();
	auto const yy_size = yy.size();
	auto arr = new int* [xx_size];
	for (int i = 0; i < xx_size; i++) {
		arr[i] = new int[yy_size]();
		for (int j = 0; j < yy_size; j++) {
			if (i > 0) arr[i][j] = arr[i - 1][j];
			if (j > 0) arr[i][j] += arr[i][j - 1];
			if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			if (binary_search(a, a + n, make_pair(xx[i], yy[j]))) {
				arr[i][j]++;
			}
		}
	}
	int min = 111111111;
	for (int i = 0; i < xx_size; i++) {
		for (int j = 0; j < xx_size; j++) {
			for (int k = 0; k < yy_size; k++) {
				int l = 0, r = k + 1;
				while (l < r) {
					auto const m = (l + r) / 2;
					auto cnt = arr[j][k];
					if (i > 0) cnt -= arr[i - 1][k];
					if (m > 0) cnt -= arr[j][m - 1];
					if (i > 0 && m > 0) cnt += arr[i - 1][m - 1];
					if (cnt < n / 2) r = m;
					else {
						if (min > (xx[j] - xx[i] + 2) * (yy[k] - yy[m] + 2)) min = (xx[j] - xx[i] + 2) * (yy[k] - yy[m] + 2);
						l = m + 1;
					}
				}
			}
		}
	}
	printf("%d", min);
}