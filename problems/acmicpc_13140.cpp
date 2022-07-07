#include <cstdio>
int main() {
	int n; scanf("%d", &n);
	for(int h = 1; h < 10; h++) {
		for(int e = 0; e < 10; e++) {
			if(e == h) continue;
			for(int l = 0; l < 10; l++) {
				if(l == h || l == e) continue;
				for(int o = 0; o < 10; o++) {
					if(o == h || o == e || o == l) continue;
					for(int w = 1; w < 10; w++) {
						if(w == h || w == e || w == l || w == o) continue;
						for(int r = 0; r < 10; r++) {
							if(r == h || r == e || r == l || r == o || r == w) continue;
							for(int d = 0; d < 10; d++) {
								if(d == h || d == e || d == l || d == o || d == w || d == r) continue;
								if(h * 10000 + e * 1000 + l * 120 + o * 1001 + w * 10000 + r * 100 + d == n) {
									printf("  %d%d%d%d%d\n+ %d%d%d%d%d\n-------\n%7d",h,e,l,l,o,w,o,r,l,d,n);
									return 0;
								}
							}
						}
					}
				}
			}
		}
	} printf("No Answer");
}