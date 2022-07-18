#include <cstdio>
inline int month(int m) {
	int res = 0;
	switch(m) {
		default: __builtin_unreachable();
		case 12: res += 30;
		case 11: res += 31;
		case 10: res += 30;
		case 9: res += 31;
		case 8: res += 31;
		case 7: res += 30;
		case 6: res += 31;
		case 5: res += 30;
		case 4: res += 31;
		case 3: res += 28;
		case 2: res += 31;
		case 1: return res;
	}
}
inline char const *output(int d) {
	switch(d % 7) {
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		default: __builtin_unreachable();
	}
}
int main() {
	int d, m; scanf("%d%d", &d, &m);
	printf(output(d + month(m) + 3));
}