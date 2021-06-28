#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v;
    while(n) {
        v.push_back(n % 9);
        n /= 9;
    }
    for(auto it = v.rbegin(); it != v.rend(); ++it) {
        printf("%d", *it);
    }
}