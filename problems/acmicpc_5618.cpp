#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    auto g = a[0];
    for(int i = 1; i < n; i++) g = gcd(g, a[i]);
    vector<int> v;
    for(int i = 1; i * i <= g; i++) {
        if(g % i == 0) {
            v.push_back(i);
            if(i * i != g) v.push_back(g / i);
        }
    }
    sort(v.begin(), v.end());
    for(auto now : v) printf("%d\n", now);
}