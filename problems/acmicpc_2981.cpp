#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int abs(int a){return a>0?a:-a;}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int n;
    scanf("%d",&n);
    int *a=new int[n];
    scanf("%d",&a[0]);
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        a[i-1]=abs(a[i]-a[i-1]);
    }
    int g=a[0];
    for(int i=1;i<n-1;i++){
        g=gcd(g,a[i]);
    }
    delete[] a;
    vector<int> v;
    for(int i=2;i*i<=g;i++){
        if(i*i==g)v.push_back(i);
        else if(g%i==0){v.push_back(i);v.push_back(g/i);}
    }
    sort(v.begin(),v.end());
    for(int i:v){
        printf("%d ",i);
    }
    printf("%d",g);
}