#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	queue<int> q;
	stack<int> s;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	int cur = 1;
	while(cur < n + 1) {
		if(!q.empty() && q.front() == cur) {
			q.pop(); cur++;
			continue;
		}
		if(!s.empty() && s.top() == cur) {
			s.pop(); cur++;
			continue;
		}
		if(!q.empty()) { s.push(q.front()); q.pop(); }
		else break;
	}
	if(cur != n + 1) printf("Sad");
	else printf("Nice");
}