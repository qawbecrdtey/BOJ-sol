#include <stdio.h>
#include <set>
using namespace std;
int main(){
    set<int> s;
    for(int i=0;i<10;i++){
        int x;
        scanf("%d",&x);
        s.insert(x%42);
    }
    printf("%d",s.size());
}