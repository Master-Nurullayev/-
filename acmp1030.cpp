#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
long double a,b,c,d,h;
	cin>>a>>b>>c>>d;
	h=min(a,b)+min(c,d);
	long double mid,r,l=1;
	r=h;
	mid=(r+l)/2;
	while(1){
		if((int)sqrt(h)-(int)mid==0||(int)sqrt(h)-(int)l==0||(int)sqrt(h)-(int)r==0) break;
		if(mid*mid<h){ 
			l=mid+1;
			mid=(r+l)/2;
		}
		if(mid*mid>h){
			r=mid-1;
			mid=(r+l)/2;
		}
	}
	if((int)sqrt(h)-(int)mid==0)
	cout<<(int)mid;
	else if((int)sqrt(h)-(int)l==0) cout<<(int) l;
	else cout<<(int)r;
	return 0;
}
