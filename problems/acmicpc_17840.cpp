#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
using ll = unsigned long long;
void insert(vector<ll> &v, ll cur) {
    vector<ll> tmp;
    if(!cur) v.push_back(0);
    else while(cur) {
        tmp.push_back(cur % 10);
        cur /= 10;
    }
    for(auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
        v.push_back(*it);
    }
}
int main() {
    ll q, m;
    scanf("%llu%llu", &q, &m);
    vector<ll> v{ 0 };
    ll cur = 1, prev = 0;
    while(cur != 0 || prev != 1) {
        insert(v, cur);
        ll next = (cur + prev) % m;
        prev = cur;
        cur = next;
    }
    for(auto now : v) printf("%llu ", now); printf("\n");
    while(q--) {
        ll x; scanf("%llu", &x);
        printf("%llu\n", v[x % v.size()]);
    }
}