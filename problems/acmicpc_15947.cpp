#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int x = (n - 1) % 14;
	int k = (n - 1) / 14;
	switch(x) {
		case 0: cout << "baby"; return 0;
		case 1: cout << "sukhwan"; return 0;
		case 4: cout << "very"; return 0;
		case 5: cout << "cute"; return 0;
		case 8: cout << "in"; return 0;
		case 9: cout << "bed"; return 0;
		case 12: cout << "baby"; return 0;
		case 13: cout << "sukhwan"; return 0;
		case 2:
		case 6:
		case 10:
			k += 2;
			if(k >= 5) {
				cout << "tu+ru*" << k;
			} else {
				cout << "tu";
				for(int i = 0; i < k; i++) cout << "ru";
			} return 0;
		case 3:
		case 7:
		case 11:
			k++;
			if(k >= 5) {
				cout << "tu+ru*" << k;
			} else {
				cout << "tu";
				for(int i = 0; i < k; i++) cout << "ru";
			} return 0;
		default: __builtin_unreachable();
	}
}