#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[26]{}; char c; while(cin >> c) a[c - 'A']++;
    for(auto i : a) if(i) { cout << i; break; }
}