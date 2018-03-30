#include <bits/stdc++.h>
#define lld long long int
#define pb push_back
#define pp pop_back
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	string s[110];
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	int m[105][105];
	for(int i=0;i<a;i++){
		for(int k=0;k<b;k++){
			cin>>m[i][k];
		}
	}
	for(int i=0;i<a;i++){
		for(int k=0;k<b;k++){
			if(s[i][k]=='R'){
				if(m[i][k]==1||m[i][k]==0||m[i][k]==2||m[i][k]==3) {
					cout<<"NO";
					return 0;
				}
			}
			if(s[i][k]=='G'){
				if(m[i][k]==1||m[i][k]==0||m[i][k]==5||m[i][k]==4) {
					cout<<"NO";
					return 0;
				}
			}
			if(s[i][k]=='B'){
				if(m[i][k]==2||m[i][k]==0||m[i][k]==4||m[i][k]==6) {
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
	return 0;
}
