#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
pair<long long,long long> dfs(pair<int,int> *a, bool *b, int const n, int cnt, int cur) {
	if(cnt==n) {
		if(cur==n/2) {
			int x=0,y=0;
			for(int i=0;i<n;i++){
				if(b[i])x+=a[i].first,y+=a[i].second;
				else x-=a[i].first,y-=a[i].second;
			}
			return make_pair(x,y);
		}
		return make_pair(2000000,2000000);
	}
	b[cnt]=false;
	auto x=move(dfs(a,b,n,cnt+1,cur));
	if(cur==n/2)return x;
	b[cnt]=true;
	auto y=move(dfs(a,b,n,cnt+1,cur+1));
	if(x.first*x.first+x.second*x.second<y.first*y.first+y.second*y.second)return x;
	return y;
}
int main() {
	int tt;
	cin>>tt;
	while(tt--) {
		int n;
		cin>>n;
		auto a=new pair<int,int>[n];
		for(int i=0;i<n;i++){
			cin>>a[i].first>>a[i].second;
		}
		auto b=new bool[n];
		auto x=dfs(a,b,n,0,0);
		cout<<fixed;
		cout.precision(6);
		cout<<sqrt(x.first*x.first+x.second*x.second)<<'\n';
		delete[] b;
		delete[] a;
	}
}