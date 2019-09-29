#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    v.push_back(n);
    int cnt=0;
    do{
        int const x=n%10+n/10;
        n=(n%10)*10+x%10;
        cnt++;
    }while(find(v.begin(),v.end(),n)==v.end());
    printf("%d",cnt);
}