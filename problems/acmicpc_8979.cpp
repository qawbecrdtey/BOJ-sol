#include<stdio.h>
#include <algorithm>
struct str{int n,g,s,b;};
bool operator<(const str &a,const str &b){return a.g>b.g||(a.g==b.g&&a.s>b.s)||(a.g==b.g&&a.s==b.s&&a.b>b.b);}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    str *a=new str[n];
    str find;
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&a[i].n,&a[i].g,&a[i].s,&a[i].b);
        if(a[i].n==k){
            find.n=k;
            find.g=a[i].g;
            find.s=a[i].s;
            find.b=a[i].b;
        }
    }
    std::sort(a,a+n);
    auto x=std::lower_bound(a,a+n,find)-a;
    printf("%lld",x+1);
}