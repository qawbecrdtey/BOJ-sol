#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> row{0, m}, col{0, n};
	int k; cin >> k;
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		if(!a) row.push_back(b);
		else col.push_back(b);
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	int maxrow = 0, maxcol = 0;
	for(int i = 1; i < row.size(); i++) {
		if(row[i] - row[i - 1] > maxrow) maxrow = row[i] - row[i - 1];
	}
	for(int i = 1; i < col.size(); i++) {
		if(col[i] - col[i - 1] > maxcol) maxcol = col[i] - col[i - 1];
	}
	cout << maxrow * maxcol;
}