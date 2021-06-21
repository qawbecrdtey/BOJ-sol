#include <cstdio>
#include <algorithm>
int main(){int a[7];for(int&i:a)scanf("%d",&i);std::sort(a,a+7);int x=a[6]-a[5],y=a[6]-a[4];int z=a[6]-x-y;printf("%d %d %d",x,y,z);}