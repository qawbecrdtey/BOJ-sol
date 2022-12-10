#include <cstdio>
int min(int a, int b) { return a > b ? b : a; }
int main() {
	int t, one{}, two{}, three{}, ans{}; scanf("%d", &t); while(t--) {
		int a, b; scanf("%d/%d", &a, &b);
		if(b == 2) two++;
		else if(a == 1) one++;
		else three++;
	}
	int x = min(one, three);
	ans += x; one -= x; three -= x;
	ans += two / 2;
	two = (two & 1);
	ans += three;
	if(two) {
		if(one > 1) {
			ans++;
			one -= 2;
		}
		else if(one == 1) {
			ans++;
			one = 0;
		}
		else {
			ans++;
		}
	}
	ans += (one + 3) / 4;
	printf("%d", ans);
}