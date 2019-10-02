#include <stdio.h>
#include <set>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int m=n*2;
    set<int> s;
    int max=0;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        if(s.find(x)!=s.end())s.erase(x);
        else s.insert(x);
        max=(max>s.size()?max:s.size());
    }
    printf("%d",max);
}