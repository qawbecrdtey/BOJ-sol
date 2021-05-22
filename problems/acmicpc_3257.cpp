#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	auto arr = new int*[a.size() + 1];
	for(int i = 0; i <= a.size(); i++) {
		arr[i] = new int[b.size() + 1]();
	}
	for(int i = 0; i <= a.size(); i++) {
		for(int j = 0; j <= b.size(); j++) {
			if(i == 0 && j == 0) continue;
			if(i == 0) {
				if(b[j - 1] == c[j - 1]) {
					arr[0][j] = arr[0][j - 1] + 1;
				}
			}
			else if(j == 0) {
				if(a[i - 1] == c[i - 1]) {
					arr[i][0] = arr[i - 1][0] + 1;
				}
			}
			else {
				if(a[i - 1] == c[i + j - 1]) {
					arr[i][j] = arr[i - 1][j] + 1;
				}
				if(b[j - 1] == c[i + j - 1]) {
					if(arr[i][j] < arr[i][j - 1] + 1) arr[i][j] = arr[i][j - 1] + 1;
				}
			}
		}
	}
	auto i = a.size(), j = b.size();
	stack<int> s;
	while(i || j) {
		if(i && arr[i - 1][j] + 1 == arr[i][j]) { s.push(1); i--; }
		else { s.push(2); j--; }
	}
	while(!s.empty()) {
		cout << s.top(); s.pop();
	}
}