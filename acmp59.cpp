#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
	int a,b,ans,h=1,g=0;
	cin>>a>>b;
	vector<int>m;
	while(a!=0){
		m.pb(a%b);
		a=a/b;
	}
	for(int i=0;i<m.size();i++){
		h*=m[i];
		g+=m[i];
	}
	cout<<h-g;
	return 0;
}
