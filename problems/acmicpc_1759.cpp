#include <stdio.h>
#include <algorithm>
void dfs(char *arr, int const l, int const c, int cur, int cnt, int v, int s, bool *check) {
	if(cnt == l) {
		if(v == 0 || s < 2) return;
		for(int i = 0; i < c && cnt; i++) {
			if(!check[i]) continue;
			printf("%c", arr[i]);
			cnt--;
		}
		printf("\n");
		return;
	}
	for(int i = cur; i < c; i++) {
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') v++;
		else s++;
		check[i] = true; cnt++;
		dfs(arr, l, c, i + 1, cnt, v, s, check);
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') v--;
		else s--;
		check[i] = false; cnt--;
	}
}
int main() {
	int l, c;
	scanf("%d%d\n", &l, &c);
	auto arr = new char[c];
	for(int i = 0; i < c - 1; i++) {
		scanf("%c ", &arr[i]);
	}
	scanf("%c", &arr[c - 1]);
	std::sort(arr, arr + c);
	auto check = new bool[c]();
	dfs(arr, l, c, 0, 0, 0, 0, check);
	delete[] check;
	delete[] arr;
}