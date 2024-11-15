#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    auto res = new int[n];
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= a[i]) s.pop();
        res[i] = static_cast<int>(s.size());
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++) cout << res[i] << ' ';
}
