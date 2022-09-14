#include <iostream>
using namespace std;
void f(bool visited[8][8], int x, int y) {
	for(int i = 0; i < 8; i++) {
		visited[i][y] = true;
		visited[x][i] = true;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	char a[8][9];
	bool visited[8][8]{};
	for(auto &i : a) {
		cin >> i;
	}
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(a[i][j] == 'R') f(visited, i, j);
		}
	} int cnt = 0;
	for(auto &i : visited) {
		for(bool j : i) {
			cnt += !j;
		}
	} cout << cnt;
}