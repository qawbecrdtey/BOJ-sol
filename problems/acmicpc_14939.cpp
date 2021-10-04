#include <iostream>
using namespace std;
void copy(char const a[10][11], bool b[10][10]) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			b[i][j] = (a[i][j] == 'O');
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char a[10][11];
	for(auto &row : a) cin >> row;
	int min = 1000000000;
	for(int i = 0; i < (1 << 10); i++) {
		int cnt = 0;
		bool b[10][10];
		copy(a, b);
		for(int j = 0; j < 10; j++) {
			if(i & (1 << j)) {
				cnt++;
				b[0][j] = !b[0][j];
				b[1][j] = !b[1][j];
				if(j) b[0][j - 1] = !b[0][j - 1];
				if(j < 9) b[0][j + 1] = !b[0][j + 1];
			}
		}
		for(int j = 1; j < 10; j++) {
			for(int k = 0; k < 10; k++) {
				if(b[j - 1][k]) {
					cnt++;
					b[j - 1][k] = false;
					b[j][k] = !b[j][k];
					if(k) b[j][k - 1] = !b[j][k - 1];
					if(k < 9) b[j][k + 1] = !b[j][k + 1];
					if(j < 9) b[j + 1][k] = !b[j + 1][k];
				}
			}
		}
		bool flag = true;
		for(int j = 0; j < 10; j++) {
			if(b[9][j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			if(min > cnt) min = cnt;
		}
	}
	if(min == 1000000000) cout << -1;
	else cout << min;
}