#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		string s, t; int n;
		cin >> s >> n >> t;
		deque<int> dq;
		int idx = 1;
		for(int i = 0; i < n; i++) {
			int x = 0;
			while(t[idx] >= '0' && t[idx] <= '9') {
				x *= 10;
				x += t[idx++] - '0';
			}
			dq.push_back(x);
			idx++;
		}
		bool turn = false;
		for(auto c : s) {
			switch(c) {
				case 'D':
					if(dq.empty()) goto END;
					if(!turn) dq.pop_front();
					else dq.pop_back();
					break;
				case 'R': turn = !turn; break;
			}
		}
		if(!turn) {
			printf("[");
			for(int i = 0; i < dq.size(); i++) {
				printf("%d", dq[i]);
				if(i < dq.size() - 1) printf(",");
			}
			printf("]\n");
		}
		else {
			printf("[");
			for(int i = 0; i < dq.size(); i++) {
				printf("%d", dq[dq.size() - i - 1]);
				if(i < dq.size() - 1) printf(",");
			}
			printf("]\n");
		}
		continue;
		END:
		printf("error\n");
	}
}