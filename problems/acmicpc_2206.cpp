#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = new char*[n];
	bool **visited[2];
	visited[0] = new bool*[n];
	visited[1] = new bool*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new char[m + 1];
		visited[0][i] = new bool[m]();
		visited[1][i] = new bool[m]();
		scanf("%s", a[i]);
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	while(!q.empty()) {
		auto const now = q.front(); q.pop();
		if(visited[now.first.first][now.second.first][now.second.second]) continue;
		visited[now.first.first][now.second.first][now.second.second] = true;
		if(now.second.first == n - 1 && now.second.second == m - 1) {
			printf("%d", now.first.second + 1);
			goto END;
		}
		if(now.second.first) {
			if(!visited[1][now.second.first - 1][now.second.second] && a[now.second.first - 1][now.second.second] == '1' && !now.first.first) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first - 1, now.second.second)));
			}
			else if(!visited[now.first.first][now.second.first - 1][now.second.second] && a[now.second.first - 1][now.second.second] == '0') {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first - 1, now.second.second)));
			}
		}
		if(now.second.second) {
			if(!visited[1][now.second.first][now.second.second - 1] && a[now.second.first][now.second.second - 1] == '1' && !now.first.first) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first, now.second.second - 1)));
			}
			else if(!visited[now.first.first][now.second.first][now.second.second - 1] && a[now.second.first][now.second.second - 1] == '0') {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first, now.second.second - 1)));
			}
		}
		if(now.second.first < n - 1) {
			if(!visited[1][now.second.first + 1][now.second.second] && a[now.second.first + 1][now.second.second] == '1' && !now.first.first) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first + 1, now.second.second)));
			}
			else if(!visited[now.first.first][now.second.first + 1][now.second.second] && a[now.second.first + 1][now.second.second] == '0') {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first + 1, now.second.second)));
			}
		}
		if(now.second.second < m - 1) {
			if(!visited[1][now.second.first][now.second.second + 1] && a[now.second.first][now.second.second + 1] == '1' && !now.first.first) {
				q.push(make_pair(make_pair(1, now.first.second + 1), make_pair(now.second.first, now.second.second + 1)));
			}
			else if(!visited[now.first.first][now.second.first][now.second.second + 1] && a[now.second.first][now.second.second + 1] == '0') {
				q.push(make_pair(make_pair(now.first.first, now.first.second + 1), make_pair(now.second.first, now.second.second + 1)));
			}
		}
	}
	printf("-1");
	END:
	for(int i = 0; i < n; i++) {
		delete[] a[i];
		delete[] visited[0][i];
		delete[] visited[1][i];
	}
	delete[] a;
	delete[] visited[0];
	delete[] visited[1];
}