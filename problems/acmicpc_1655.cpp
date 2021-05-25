#include <stdio.h>
#include <queue>
using namespace std;
struct comp{ bool operator()(int a, int b) { return a > b; } };
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> l;
	priority_queue<int, vector<int>, comp> r;
	queue<int> s;
	while(n--) {
		int x;
		scanf("%d", &x);
		if(!l.empty() && x < l.top()) {
			auto const cur = l.top(); l.pop();
			l.push(x);
			x = cur;
		}
		else if(!r.empty() && x > r.top()) {
			auto const cur = r.top(); r.pop();
			r.push(x);
			x = cur;
		}
		if(l.size() == r.size()) {
			printf("%d\n", x);
			l.push(x);
		}
		else {
			printf("%d\n", l.top());
			r.push(x);
		}
	}
}